#include "BVEnhancedInputUserSettings.h"


void UBVEnhancedInputUserSettings::ResetInputSettings()
{
	SprintMode = DefaultSprintMode;
	CrouchMode = DefaultCrouchMode;
	AimSensitivityHorizontal = DefaultAimSensitivityHorizontal;
	AimSensitivityVertical = DefaultAimSensitivityVertical;
	bInvertHorizontalAxis = bDefaultInvertHorizontalAxis;
	bInvertVerticalAxis = bDefaultInvertVerticalAxis;
}
