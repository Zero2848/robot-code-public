#ifndef C2017_WPILIB_SUPERSTRUCTURE_INTERFACE_H_
#define C2017_WPILIB_SUPERSTRUCTURE_INTERFACE_H_

#include "WPILib.h"
#include "muan/wpilib/pcm_wrapper.h"
#include "muan/wpilib/can_wrapper.h"
#include "c2017/queue_manager/queue_manager.h"
#include "muan/utils/math_utils.h"

namespace c2017 {

namespace wpilib {

class SuperStructureInterface {
 public:
  SuperStructureInterface(muan::wpilib::CanWrapper* can_wrapper);

  void WriteActuators();
  void ReadSensors();

 private:
  c2017::shooter::ShooterInputQueue shooter_input_queue_;
  c2017::trigger::TriggerInputQueue trigger_input_queue_;
  c2017::climber::ClimberInputQueue climber_input_queue_;

  c2017::magazine::MagazineInputQueue magazine_input_queue_;
  c2017::ground_gear_intake::GroundGearIntakeInputQueue ground_gear_input_queue_;

  c2017::wpilib::WpilibOutputQueue::QueueReader output_queue_;

  VictorSP shooter_motor_;
  VictorSP trigger_motor_;
  VictorSP brush_motor_;
  VictorSP ball_intake_motor_;
  VictorSP gear_intake_motor_;

  Encoder shooter_encoder_;
  Encoder trigger_encoder_;

  muan::wpilib::PcmWrapper* pcm_;
};

}

}

#endif // C2017_WPILIB_SUPERSTURCTURE_INTERFACE_H_
