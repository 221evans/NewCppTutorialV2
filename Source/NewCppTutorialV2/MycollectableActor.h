#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MycollectableActor.generated.h"

UCLASS()
class NEWCPPTUTORIALV2_API AMycollectableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMycollectableActor();

	UFUNCTION(BlueprintCallable)
	void Jump(float velocity);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Static mesh for rendering
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere)
	float LiveTime = 2.f;
	bool IsLaunched = false;
	
};
