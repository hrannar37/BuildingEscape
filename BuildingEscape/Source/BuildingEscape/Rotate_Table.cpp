// Copyright Mike_Tengu  2017

#include "Rotate_Table.h"
#include "GameFramework/Actor.h"

float RotationValue = 0.0f;

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


	// ...
	
}


// Called every frame
void URotate_Table::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* Table_Owner = GetOwner();
	RotationValue = (RotationValue + 4.0);
	if (RotationValue >= 360) { RotationValue = 0; };
	UE_LOG(LogTemp, Warning, TEXT("Rotation Value Is %f"), RotationValue);

	FRotator NewRotation = FRotator(0.0f, (RotationValue), 0.0f);

	Table_Owner->SetActorRotation(NewRotation);
	// ...
}

