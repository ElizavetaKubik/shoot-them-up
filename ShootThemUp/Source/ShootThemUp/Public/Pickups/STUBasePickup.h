// Shoot Them Up Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUBasePickup.generated.h"

class USphereComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUBasePickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASTUBasePickup();

protected:

	UPROPERTY(VisibleAnywhere, Category="Pickup")
	USphereComponent* CollisionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pickup")
	float RespawnTime = 5.0f;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	bool CouldBeTaken() const;

private:

	FTimerHandle RespawnTimerHandle;
	float RotationYaw = 0.0f;

	void GenerateRotationYaw();
	void PickupWasTaken();
	void Respawn();
	virtual bool GivePickupTo(APawn* PlayerPawn);

};
