// Copyright Mike_Tengu  2017

#include "Rotate_Table.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
URotate_Table::URotate_Table()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotate_Table::BeginPlay()
{
	Super::BeginPlay();

	int32 Table_Z_Rotation = GetOwner()->GetTransform().GetRotation().Z;
	UE_LOG(LogTemp, Warning, TEXT("Z Rotation is %d"), *Table_Z_Rotation)

	// ...
	
}


// Called every frame
void URotate_Table::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

