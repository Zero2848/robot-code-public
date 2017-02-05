#include <WPILib.h>
#include "c2017/wpilib_update/main.h"
#include "subsystems/subsystem_runner.h"
#include "vision/robot/reader.h"

class WpilibRobot : public IterativeRobot {
 public:
  WpilibRobot() { c2017::QueueManager::GetInstance().StartLogging(); }

  void TeleopPeriodic() override { main_.Update(); }

  void AutonomousPeriodic() override { main_.Update(); }

 private:
  c2017::SubsystemRunner subsystem_runner_;
  c2017::vision::VisionReader vision_reader_;
  std::thread subsystem_thread{std::ref(subsystem_runner_)};
  std::thread vision_thread{std::ref(vision_reader_)};

  c2017::citrus_robot::CitrusRobot main_;
};

START_ROBOT_CLASS(WpilibRobot);
