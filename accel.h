/*
 * accel.h
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

#ifndef RTW_HEADER_accel_h_
#define RTW_HEADER_accel_h_
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "accel_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
struct B_accel_T {
  SL_Bus_accel_geometry_msgs_Twist BusAssignment;/* '<Root>/Bus Assignment' */
  SL_Bus_accel_geometry_msgs_Twist In1;/* '<S54>/In1' */
  SL_Bus_accel_geometry_msgs_Twist b_varargout_2;
  real_T error;                        /* '<Root>/Sum' */
  real_T Sum;                          /* '<S46>/Sum' */
  real_T measuredoutput;               /* '<Root>/Transfer Fcn' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_accel_T {
  ros_slroscpp_internal_block_P_T obj; /* '<S3>/SinkBlock' */
  ros_slroscpp_internal_block_S_T obj_e;/* '<S4>/SourceBlock' */
  real_T Filter_DSTATE;                /* '<S32>/Filter' */
  real_T Integrator_DSTATE;            /* '<S37>/Integrator' */
  boolean_T objisempty;                /* '<S4>/SourceBlock' */
  boolean_T objisempty_c;              /* '<S3>/SinkBlock' */
};

/* Continuous states (default storage) */
struct X_accel_T {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
};

/* State derivatives (default storage) */
struct XDot_accel_T {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
};

/* State disabled  */
struct XDis_accel_T {
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T TransferFcn_CSTATE;        /* '<Root>/Transfer Fcn' */
};

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
struct ODE3_IntgData {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
};

#endif

/* Parameters (default storage) */
struct P_accel_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S31>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S34>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S32>/Filter'
                               */
  real_T PIDController_InitialConditio_p;
                              /* Mask Parameter: PIDController_InitialConditio_p
                               * Referenced by: '<S37>/Integrator'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S40>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S42>/Proportional Gain'
                                        */
  SL_Bus_accel_geometry_msgs_Twist Constant_Value;/* Computed Parameter: Constant_Value
                                                   * Referenced by: '<S1>/Constant'
                                                   */
  SL_Bus_accel_geometry_msgs_Twist Out1_Y0;/* Computed Parameter: Out1_Y0
                                            * Referenced by: '<S54>/Out1'
                                            */
  SL_Bus_accel_geometry_msgs_Twist Constant_Value_o;/* Computed Parameter: Constant_Value_o
                                                     * Referenced by: '<S4>/Constant'
                                                     */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S32>/Filter'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S37>/Integrator'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_accel_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_accel_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern P_accel_T accel_P;

#ifdef __cplusplus

}
#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_accel_T accel_B;

#ifdef __cplusplus

}
#endif

/* Continuous states (default storage) */
extern X_accel_T accel_X;

/* Block states (default storage) */
extern struct DW_accel_T accel_DW;

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void accel_initialize(void);
  extern void accel_step(void);
  extern void accel_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_accel_T *const accel_M;

#ifdef __cplusplus

}
#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'accel'
 * '<S1>'   : 'accel/Blank Message'
 * '<S2>'   : 'accel/Controller'
 * '<S3>'   : 'accel/Publish'
 * '<S4>'   : 'accel/Subscribe'
 * '<S5>'   : 'accel/Controller/PID Controller'
 * '<S6>'   : 'accel/Controller/PID Controller/Anti-windup'
 * '<S7>'   : 'accel/Controller/PID Controller/D Gain'
 * '<S8>'   : 'accel/Controller/PID Controller/Filter'
 * '<S9>'   : 'accel/Controller/PID Controller/Filter ICs'
 * '<S10>'  : 'accel/Controller/PID Controller/I Gain'
 * '<S11>'  : 'accel/Controller/PID Controller/Ideal P Gain'
 * '<S12>'  : 'accel/Controller/PID Controller/Ideal P Gain Fdbk'
 * '<S13>'  : 'accel/Controller/PID Controller/Integrator'
 * '<S14>'  : 'accel/Controller/PID Controller/Integrator ICs'
 * '<S15>'  : 'accel/Controller/PID Controller/N Copy'
 * '<S16>'  : 'accel/Controller/PID Controller/N Gain'
 * '<S17>'  : 'accel/Controller/PID Controller/P Copy'
 * '<S18>'  : 'accel/Controller/PID Controller/Parallel P Gain'
 * '<S19>'  : 'accel/Controller/PID Controller/Reset Signal'
 * '<S20>'  : 'accel/Controller/PID Controller/Saturation'
 * '<S21>'  : 'accel/Controller/PID Controller/Saturation Fdbk'
 * '<S22>'  : 'accel/Controller/PID Controller/Sum'
 * '<S23>'  : 'accel/Controller/PID Controller/Sum Fdbk'
 * '<S24>'  : 'accel/Controller/PID Controller/Tracking Mode'
 * '<S25>'  : 'accel/Controller/PID Controller/Tracking Mode Sum'
 * '<S26>'  : 'accel/Controller/PID Controller/Tsamp - Integral'
 * '<S27>'  : 'accel/Controller/PID Controller/Tsamp - Ngain'
 * '<S28>'  : 'accel/Controller/PID Controller/postSat Signal'
 * '<S29>'  : 'accel/Controller/PID Controller/preSat Signal'
 * '<S30>'  : 'accel/Controller/PID Controller/Anti-windup/Passthrough'
 * '<S31>'  : 'accel/Controller/PID Controller/D Gain/Internal Parameters'
 * '<S32>'  : 'accel/Controller/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S33>'  : 'accel/Controller/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S34>'  : 'accel/Controller/PID Controller/I Gain/Internal Parameters'
 * '<S35>'  : 'accel/Controller/PID Controller/Ideal P Gain/Passthrough'
 * '<S36>'  : 'accel/Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S37>'  : 'accel/Controller/PID Controller/Integrator/Discrete'
 * '<S38>'  : 'accel/Controller/PID Controller/Integrator ICs/Internal IC'
 * '<S39>'  : 'accel/Controller/PID Controller/N Copy/Disabled'
 * '<S40>'  : 'accel/Controller/PID Controller/N Gain/Internal Parameters'
 * '<S41>'  : 'accel/Controller/PID Controller/P Copy/Disabled'
 * '<S42>'  : 'accel/Controller/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S43>'  : 'accel/Controller/PID Controller/Reset Signal/Disabled'
 * '<S44>'  : 'accel/Controller/PID Controller/Saturation/Passthrough'
 * '<S45>'  : 'accel/Controller/PID Controller/Saturation Fdbk/Disabled'
 * '<S46>'  : 'accel/Controller/PID Controller/Sum/Sum_PID'
 * '<S47>'  : 'accel/Controller/PID Controller/Sum Fdbk/Disabled'
 * '<S48>'  : 'accel/Controller/PID Controller/Tracking Mode/Disabled'
 * '<S49>'  : 'accel/Controller/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S50>'  : 'accel/Controller/PID Controller/Tsamp - Integral/Passthrough'
 * '<S51>'  : 'accel/Controller/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S52>'  : 'accel/Controller/PID Controller/postSat Signal/Forward_Path'
 * '<S53>'  : 'accel/Controller/PID Controller/preSat Signal/Forward_Path'
 * '<S54>'  : 'accel/Subscribe/Enabled Subsystem'
 */
#endif                                 /* RTW_HEADER_accel_h_ */
