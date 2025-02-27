

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MoveComponent.generated.h"

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveComponentReachEndPointSignature, bool, IsTopEndpoint);

UCLASS( ClassGroup=(Movement), meta=(BlueprintSpawnableComponent) )
class NEWCPPTUTORIALV2_API UMoveComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoveComponent();

	UFUNCTION(BlueprintCallable)
	void EnableMovement(bool ShouldMove);

	UFUNCTION(BlueprintCallable)
	void ResetMovement();

	UFUNCTION(BlueprintCallable)
	void SetMoveDirection(int Direction);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
private:
	// Parameter
	UPROPERTY(EditAnywhere)
	FVector MoveOffset;
	
	UPROPERTY(EditAnywhere)
	float Speed = 1.0f;
	// Enables movement of the component
	UPROPERTY(EditAnywhere)
	bool MoveEnable = true;

	//On extreme reached event

	UPROPERTY(BlueprintAssignable)
	FOnMoveComponentReachEndPointSignature OnEndPointReached;
	
	// Computed locations 
	FVector StartRelativeLocation;
	FVector MoveOffsetNorm;
	float MaxDistance = 0.0f;
	float CurDistance = 0.0f;
	int MoveDirection = 1;
		
};
