// Copyright Mike_Tengu  2017

#include "Ball_Key.h"
//#include "Engine/World.h" for function complete purposes


// Sets default values for this component's properties
UBall_Key::UBall_Key()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBall_Key::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBall_Key::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

