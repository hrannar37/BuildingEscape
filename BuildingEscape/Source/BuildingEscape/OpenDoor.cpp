// Copyright Mike_Tengu  2017

#include "OpenDoor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	if (!PressurePlate) { 
		UE_LOG(LogTemp, Error, TEXT("Cannot find the trigger volume for the OpenDoor"))
		return; 
	}
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!PressurePlate) { return; }
	if (PressurePlate->IsOverlappingActor(ActorThatOpens)) 
	{
		OnOpenRequest.Broadcast();
	}
	else { OnCloseRequest.Broadcast(); }
}

