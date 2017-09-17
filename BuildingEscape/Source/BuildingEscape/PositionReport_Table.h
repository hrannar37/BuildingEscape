// Copyright Mike_Tengu  2017

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PositionReport_Table.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UPositionReport_Table : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPositionReport_Table();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
