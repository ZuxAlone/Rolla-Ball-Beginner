// Fill out your copyright notice in the Description page of Project Settings.


#include "RollBallItemBase.h"
#include <RollBallProject/Game/RollBallPlayer.h>

// Sets default values
ARollBallItemBase::ARollBallItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create Components - Before this step they won't exist on our Actor, they've only been defined.
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	RootComponent = Mesh;

	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ARollBallItemBase::OverlapBegin);
}

// Called when the game starts or when spawned
void ARollBallItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARollBallItemBase::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
									 int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<ARollBallPlayer>(OtherActor) != nullptr)
	{
		Collected();
	}
}

void ARollBallItemBase::Collected_Implementation()
{
	// TODO - Do Game Mode Stuffs

}

