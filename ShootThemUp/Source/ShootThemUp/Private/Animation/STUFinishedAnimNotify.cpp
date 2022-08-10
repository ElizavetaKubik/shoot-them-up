// Shoot Them Up Game. All Rights Reserved.


#include "Animation/STUFinishedAnimNotify.h"

void USTUFinishedAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	OnNotified.Broadcast(MeshComp);
		
	Super::Notify(MeshComp, Animation);
}
