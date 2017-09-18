// Copyright Mike_Tengu  2017

#include "OpenDoor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	Owner->SetActorRotation(ClosedState);

	// ...
	
}

void UOpenDoor::OpenDoor()
{
	AActor* Owner = GetOwner();
	float RotationValue = 0.0f;
	FRotator OpenState = FRotator(0.0f, (OpenAngle), 0.0f);
	Owner->SetActorRotation(OpenState);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* Owner = GetOwner();
	if (PressurePlate->IsOverlappingActor(ActorThatOpens)) { OpenDoor(); }
	else { Owner->SetActorRotation(ClosedState); };
}

