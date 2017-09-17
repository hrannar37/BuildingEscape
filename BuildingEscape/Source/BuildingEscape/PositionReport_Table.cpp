// Copyright Mike_Tengu  2017

#include "PositionReport_Table.h"


// Sets default values for this component's properties
UPositionReport_Table::UPositionReport_Table()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReport_Table::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Position Reporter Reporting For Table!"))
	// ...
	
}


// Called every frame
void UPositionReport_Table::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

