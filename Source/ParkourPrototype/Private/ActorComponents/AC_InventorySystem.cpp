// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorComponents/AC_InventorySystem.h"

// Sets default values for this component's properties
UAC_InventorySystem::UAC_InventorySystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_InventorySystem::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAC_InventorySystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UAC_InventorySystem::IsMissingItems(const TArray<FDecreaseItem> Items, TArray<FDecreaseItem>& MissingItems)
{
	int length = Items.Num();
	bool CanProceed = true;

	for (int i = 0; i < length; i++) {

		FDecreaseItem Temp = Items[i];

		switch (Temp.Type) {
		case EItemTypes::Consumables:
		{
			if (Consumables[Temp.index].Count < Temp.Amount) {
				MissingItems.Add(Temp);
				CanProceed = false;
			}
			break;
		}
		case EItemTypes::Materials:
		{
			if (Materials[Temp.index].Count < Temp.Amount) {
				MissingItems.Add(Temp);
				CanProceed = false;
			}
			break;
		}
		case EItemTypes::Parts:
		{
			if (Parts[Temp.index].Count < Temp.Amount) {
				MissingItems.Add(Temp);
				CanProceed = false;
			}
			break;
		}
		case EItemTypes::Tools:
		{
			if (Tools[Temp.index].Count < Temp.Amount) {
				MissingItems.Add(Temp);
				CanProceed = false;
			}
			break;
		}
		}
	}
	if (!CanProceed) {
		return false;
	}
	return true;
	
}

bool UAC_InventorySystem::DecreaseItems(const TArray<FDecreaseItem> Items)
{
	int length = Items.Num();

	for (int i = 0; i < length; i++) {

		FDecreaseItem Temp = Items[i];

		switch (Temp.Type) {
			case EItemTypes::Consumables:
			{
				if (Consumables[Temp.index].Count < Temp.Amount) {
					return false;
				}
				break;
			}
			case EItemTypes::Materials:
			{
				if (Materials[Temp.index].Count < Temp.Amount) {
					return false;
				}
				break;
			}
			case EItemTypes::Parts:
			{
				if (Parts[Temp.index].Count < Temp.Amount) {
					return false;
				}
				break;
			}
			case EItemTypes::Tools:
			{
				if (Tools[Temp.index].Count < Temp.Amount) {
					return false;
				}
				break;
			}
		}
	}

	for (int i = 0; i < length; i++) {

		FDecreaseItem Temp = Items[i];
		if (Temp.Amount <= 0) {
			continue;
		}
		switch (Temp.Type) {
			case EItemTypes::Consumables:
			{
				Consumables[Temp.index].Count -= Temp.Amount;
				ItemCarryAmount -= Consumables[Temp.index].ItemWeight;
				break;
			}
			case EItemTypes::Materials:
			{
				Materials[Temp.index].Count -= Temp.Amount;
				ItemCarryAmount -= Materials[Temp.index].ItemWeight;
				break;
			}
			case EItemTypes::Parts:
			{
				Parts[Temp.index].Count -= Temp.Amount;
				ItemCarryAmount -= Parts[Temp.index].ItemWeight;
				break;
			}
			case EItemTypes::Tools:
			{
				Tools[Temp.index].Count -= Temp.Amount;
				ItemCarryAmount -= Tools[Temp.index].ItemWeight;
				break;
			}
		}
	}

	


	return true;
}

bool UAC_InventorySystem::DecreaseItemsMeta(const TArray<FDecreaseItem> Items, TArray<FDecreaseItem>&MissingItems)
{
	int length = Items.Num();
	bool CanProceed = true;

	for (int i = 0; i < length; i++) {

		FDecreaseItem Temp = Items[i];
		
		switch (Temp.Type) {
		case EItemTypes::Consumables:
		{
			if (Consumables[Temp.index].Count < Temp.Amount) {
				MissingItems.Add(Temp);
			    CanProceed = false;
			}
			break;
		}
		case EItemTypes::Materials:
		{
			if (Materials[Temp.index].Count < Temp.Amount) {
				MissingItems.Add(Temp);
				CanProceed = false;
			}
			break;
		}
		case EItemTypes::Parts:
		{
			if (Parts[Temp.index].Count < Temp.Amount) {
				MissingItems.Add(Temp);
				CanProceed = false;
			}
			break;
		}
		case EItemTypes::Tools:
		{
			if (Tools[Temp.index].Count < Temp.Amount) {
				MissingItems.Add(Temp);
				CanProceed = false;
			}
			break;
		}
		}
	}
	if (!CanProceed) {
		return false;
	}


	for (int i = 0; i < length; i++) {

		FDecreaseItem Temp = Items[i];
		if (Temp.Amount <= 0) {
			continue;
		}
		switch (Temp.Type) {
		case EItemTypes::Consumables:
		{
			Consumables[Temp.index].Count -= Temp.Amount;
			ItemCarryAmount -= Consumables[Temp.index].ItemWeight;
			break;
		}
		case EItemTypes::Materials:
		{
			Materials[Temp.index].Count -= Temp.Amount;
			ItemCarryAmount -= Materials[Temp.index].ItemWeight;
			break;
		}
		case EItemTypes::Parts:
		{
			Parts[Temp.index].Count -= Temp.Amount;
			ItemCarryAmount -= Parts[Temp.index].ItemWeight;
			break;
		}
		case EItemTypes::Tools:
		{
			Tools[Temp.index].Count -= Temp.Amount;
			ItemCarryAmount -= Tools[Temp.index].ItemWeight;
			break;
		}
		}
	}




	return true;
}
