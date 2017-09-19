// Copyright Mike_Tengu  2017

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "GameFramework/Actor.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
private:
	
	UPROPERTY(EditAnywhere)
		float OpenAngle = 90.0f;
	UPROPERTY(EditAnywhere)
		float CloseAngle = 0.0f;
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate;
	UPROPERTY(EditAnywhere)
		float DoorCloseTime = 1.0f;


	float DoorLastOpenTime = 1.0f;
	AActor* ActorThatOpens;
	AActor* Owner;
	//FRotator ClosedState = FRotator(0.0f, (CloseAngle), 0.0f);
};
