// Copyright Mike_Tengu  2017

#include "Grabber.h"
#include "Engine/World.h" //TODO remove once the code is ready
#include "DrawDebugHelpers.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber Reporting"));


	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	GetPlayerViewPoint();
	DrawGrabberReachLine();
	LineTrace();
	// ..
}

void UGrabber::GetPlayerViewPoint()
{
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerLocation, PlayerViewDirection);
}

void UGrabber::DrawGrabberReachLine()
{
	FVector LineTraceEnd = PlayerLocation + (PlayerViewDirection.Vector() * Grabber_Lenght);
	DrawDebugLine(
		GetWorld(),
		PlayerLocation,
		LineTraceEnd,
		FColor(175, 238, 238),
		false,
		0.0f,
		0.f,
		3.0f
	);
}

void UGrabber::LineTrace()
{
	FCollisionQueryParams TraceParameters = (FName(TEXT("")), false, GetOwner());
	FHitResult LineTraceHit;
	FVector LineTraceEnd = PlayerLocation + (PlayerViewDirection.Vector() * Grabber_Lenght);
	GetWorld()->LineTraceSingleByObjectType(
		LineTraceHit,
		PlayerLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);
	AActor* ActorHit = LineTraceHit.GetActor();
	if (ActorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Object %s"), *(ActorHit->GetName()));
	}
}


