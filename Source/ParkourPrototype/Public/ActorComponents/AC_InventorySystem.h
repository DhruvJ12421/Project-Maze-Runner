// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_InventorySystem.generated.h"


UENUM(BlueprintType)
enum EItemTypes {
	NONE			UMETA(DisplayName = "NONE"),
	Consumables		UMETA(DisplayName = "Consumables"),
	Parts			UMETA(DisplayName = "Parts"),
	Materials		UMETA(DisplayName = "Materials"),
	Tools			UMETA(DisplayName = "Tools")

};

USTRUCT(BlueprintType)
struct FItems{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FName ItemName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ItemClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count{0};

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int ItemWeight{1};

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString Description;
};




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PARKOURPROTOTYPE_API UAC_InventorySystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_InventorySystem();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<FItems> Consumables;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItems> Parts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItems> Materials;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItems> Tools;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int MaxInventoryCapacity{ 0 };

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int ItemCarryAmount{ 0 };

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
