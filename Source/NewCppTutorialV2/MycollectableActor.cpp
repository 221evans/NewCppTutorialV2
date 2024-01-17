// Fill out your copyright notice in the Description page of Project Settings.


#include "MycollectableActor.h"

// Sets default values
AMycollectableActor::AMycollectableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// create root component for rendering
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;
	
}

void AMycollectableActor::Jump(float velocity)
{
	// make sure jump is only executed once
	if(!IsLaunched)
	{
		// Execute jump using the physics system
		StaticMesh->AddImpulse({.0f,.0f,velocity * 500.f});

		// Initiate object destruction
		SetActorTickEnabled(true);
		IsLaunched = true;
	}
}


// Called when the game starts or when spawned
void AMycollectableActor::BeginPlay()
{
	Super::BeginPlay();

	// Ticking is only required after launching
	SetActorTickEnabled(false);
}

// Called every frame
void AMycollectableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(IsLaunched)
	{
		// Decrement live time
		LiveTime -= DeltaTime;

		// Check actor destruction
		if(LiveTime <= 0.0f)
		{
			Destroy();
		}
	}

}

