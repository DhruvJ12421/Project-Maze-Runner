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
	int UID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString Description;
};

USTRUCT(BlueprintType)
struct FItemTypes {
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EItemTypes> ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItems> ItemList;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PARKOURPROTOTYPE_API UAC_InventorySystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_InventorySystem();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<FItemTypes> InventorySystem;
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
