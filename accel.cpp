/*
 * accel.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "accel".
 *
 * Model version              : 1.20
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Thu Nov 11 21:35:49 2021
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "accel.h"
#include "accel_private.h"

/* Block signals (default storage) */
B_accel_T accel_B;

/* Continuous states */
X_accel_T accel_X;

/* Block states (default storage) */
DW_accel_T accel_DW;

/* Real-time model */
RT_MODEL_accel_T accel_M_ = RT_MODEL_accel_T();
RT_MODEL_accel_T *const accel_M = &accel_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  accel_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  accel_step();
  accel_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  accel_step();
  accel_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void accel_step(void)
{
  /* local block i/o variables */
  real_T rtb_FilterCoefficient;
  real_T rtb_IntegralGain;
  if (rtmIsMajorTimeStep(accel_M)) {
    /* set solver stop time */
    if (!(accel_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&accel_M->solverInfo, ((accel_M->Timing.clockTickH0
        + 1) * accel_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&accel_M->solverInfo, ((accel_M->Timing.clockTick0 +
        1) * accel_M->Timing.stepSize0 + accel_M->Timing.clockTickH0 *
        accel_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(accel_M)) {
    accel_M->Timing.t[0] = rtsiGetT(&accel_M->solverInfo);
  }

  /* BusAssignment: '<Root>/Bus Assignment' incorporates:
   *  Constant: '<S1>/Constant'
   */
  accel_B.BusAssignment = accel_P.Constant_Value;

  /* BusAssignment: '<Root>/Bus Assignment' incorporates:
   *  Integrator: '<Root>/Integrator'
   */
  accel_B.BusAssignment.Linear.X = accel_X.Integrator_CSTATE;

  /* Outputs for Atomic SubSystem: '<Root>/Publish' */
  /* MATLABSystem: '<S3>/SinkBlock' */
  Pub_accel_32.publish(&accel_B.BusAssignment);

  /* End of Outputs for SubSystem: '<Root>/Publish' */
  if (rtmIsMajorTimeStep(accel_M)) {
    boolean_T b_varargout_1;

    /* Outputs for Atomic SubSystem: '<Root>/Subscribe' */
    /* MATLABSystem: '<S4>/SourceBlock' incorporates:
     *  Inport: '<S54>/In1'
     */
    b_varargout_1 = Sub_accel_33.getLatestMessage(&accel_B.b_varargout_2);

    /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S54>/Enable'
     */
    if (b_varargout_1) {
      accel_B.In1 = accel_B.b_varargout_2;
    }

    /* End of MATLABSystem: '<S4>/SourceBlock' */
    /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/Subscribe' */
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Integrator: '<Root>/Integrator'
   */
  accel_B.error = accel_B.In1.Linear.X - accel_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(accel_M)) {
    /* Gain: '<S40>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S32>/Filter'
     *  Gain: '<S31>/Derivative Gain'
     *  Sum: '<S32>/SumD'
     */
    rtb_FilterCoefficient = (accel_P.PIDController_D * accel_B.error -
      accel_DW.Filter_DSTATE) * accel_P.PIDController_N;

    /* Sum: '<S46>/Sum' incorporates:
     *  DiscreteIntegrator: '<S37>/Integrator'
     *  Gain: '<S42>/Proportional Gain'
     */
    accel_B.Sum = (accel_P.PIDController_P * accel_B.error +
                   accel_DW.Integrator_DSTATE) + rtb_FilterCoefficient;

    /* Gain: '<S34>/Integral Gain' */
    rtb_IntegralGain = accel_P.PIDController_I * accel_B.error;
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  accel_B.measuredoutput = 0.0;
  accel_B.measuredoutput += accel_P.TransferFcn_C * accel_X.TransferFcn_CSTATE;
  if (rtmIsMajorTimeStep(accel_M)) {
    if (rtmIsMajorTimeStep(accel_M)) {
      /* Update for DiscreteIntegrator: '<S32>/Filter' */
      accel_DW.Filter_DSTATE += accel_P.Filter_gainval * rtb_FilterCoefficient;

      /* Update for DiscreteIntegrator: '<S37>/Integrator' */
      accel_DW.Integrator_DSTATE += accel_P.Integrator_gainval *
        rtb_IntegralGain;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(accel_M)) {
    rt_ertODEUpdateContinuousStates(&accel_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++accel_M->Timing.clockTick0)) {
      ++accel_M->Timing.clockTickH0;
    }

    accel_M->Timing.t[0] = rtsiGetSolverStopTime(&accel_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.05s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.05, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      accel_M->Timing.clockTick1++;
      if (!accel_M->Timing.clockTick1) {
        accel_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void accel_derivatives(void)
{
  XDot_accel_T *_rtXdot;
  _rtXdot = ((XDot_accel_T *) accel_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = accel_B.measuredoutput;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += accel_P.TransferFcn_A *
    accel_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += accel_B.Sum;
}

/* Model initialize function */
void accel_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&accel_M->solverInfo, &accel_M->Timing.simTimeStep);
    rtsiSetTPtr(&accel_M->solverInfo, &rtmGetTPtr(accel_M));
    rtsiSetStepSizePtr(&accel_M->solverInfo, &accel_M->Timing.stepSize0);
    rtsiSetdXPtr(&accel_M->solverInfo, &accel_M->derivs);
    rtsiSetContStatesPtr(&accel_M->solverInfo, (real_T **) &accel_M->contStates);
    rtsiSetNumContStatesPtr(&accel_M->solverInfo, &accel_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&accel_M->solverInfo,
      &accel_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&accel_M->solverInfo,
      &accel_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&accel_M->solverInfo,
      &accel_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&accel_M->solverInfo, (&rtmGetErrorStatus(accel_M)));
    rtsiSetRTModelPtr(&accel_M->solverInfo, accel_M);
  }

  rtsiSetSimTimeStep(&accel_M->solverInfo, MAJOR_TIME_STEP);
  accel_M->intgData.y = accel_M->odeY;
  accel_M->intgData.f[0] = accel_M->odeF[0];
  accel_M->intgData.f[1] = accel_M->odeF[1];
  accel_M->intgData.f[2] = accel_M->odeF[2];
  accel_M->contStates = ((X_accel_T *) &accel_X);
  rtsiSetSolverData(&accel_M->solverInfo, static_cast<void *>(&accel_M->intgData));
  rtsiSetSolverName(&accel_M->solverInfo,"ode3");
  rtmSetTPtr(accel_M, &accel_M->Timing.tArray[0]);
  accel_M->Timing.stepSize0 = 0.05;

  /* block I/O */
  (void) memset((static_cast<void *>(&accel_B)), 0,
                sizeof(B_accel_T));

  /* states (continuous) */
  {
    (void) memset(static_cast<void *>(&accel_X), 0,
                  sizeof(X_accel_T));
  }

  /* states (dwork) */
  (void) memset(static_cast<void *>(&accel_DW), 0,
                sizeof(DW_accel_T));

  {
    int32_T i;
    char_T b_zeroDelimTopic_0[8];
    char_T b_zeroDelimTopic[6];
    static const char_T tmp[5] = { 'v', '_', 'a', 'c', 't' };

    static const char_T tmp_0[7] = { 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    /* Start for Atomic SubSystem: '<Root>/Publish' */
    /* Start for MATLABSystem: '<S3>/SinkBlock' */
    accel_DW.obj.matlabCodegenIsDeleted = false;
    accel_DW.objisempty_c = true;
    accel_DW.obj.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[5] = '\x00';
    Pub_accel_32.createPublisher(&b_zeroDelimTopic[0], 1);
    accel_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S3>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe' */
    /* Start for MATLABSystem: '<S4>/SourceBlock' */
    accel_DW.obj_e.matlabCodegenIsDeleted = false;
    accel_DW.objisempty = true;
    accel_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[7] = '\x00';
    Sub_accel_33.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    accel_DW.obj_e.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S4>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe' */
  }

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  accel_X.Integrator_CSTATE = accel_P.Integrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S32>/Filter' */
  accel_DW.Filter_DSTATE = accel_P.PIDController_InitialConditionF;

  /* InitializeConditions for DiscreteIntegrator: '<S37>/Integrator' */
  accel_DW.Integrator_DSTATE = accel_P.PIDController_InitialConditio_p;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  accel_X.TransferFcn_CSTATE = 0.0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe' */
  /* SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S54>/Out1' incorporates:
   *  Inport: '<S54>/In1'
   */
  accel_B.In1 = accel_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe' */
}

/* Model terminate function */
void accel_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Publish' */
  /* Terminate for MATLABSystem: '<S3>/SinkBlock' */
  if (!accel_DW.obj.matlabCodegenIsDeleted) {
    accel_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/Publish' */

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe' */
  /* Terminate for MATLABSystem: '<S4>/SourceBlock' */
  if (!accel_DW.obj_e.matlabCodegenIsDeleted) {
    accel_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe' */
}
