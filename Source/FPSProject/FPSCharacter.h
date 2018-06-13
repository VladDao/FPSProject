// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFramework/GameMode.h"

#include "GameFramework/Character.h"

#include "Camera/CameraComponent.h"

#include "FPSCharacter.generated.h"
// Constructor for AFPSCharacter


UCLASS()
class FPSPROJECT_API AFPSCharacter : public ACharacter
{
	


	GENERATED_BODY()
		virtual void BeginPlay() override;
protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	//handles moving forward/backward
	UFUNCTION()
		void MoveForward(float Val);
	//handles strafing
	UFUNCTION()
		void MoveRight(float Val);
	//sets jump flag when key is pressed
	UFUNCTION()
		void OnStartJump();
	//clears jump flag when key is released
	UFUNCTION()
		void OnStopJump();
	UFUNCTION()
		void OnStartJog();
	UFUNCTION()
		void OnStopJog();
	UFUNCTION()
		void OnPressedAction();
	UFUNCTION()
		void OnReleasedAction();



public:
	// Sets default values for this character's properties
	AFPSCharacter();

/*protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;*/

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
//	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
public:


	UPROPERTY(VisibleAnywhere, Category = "Camera")
		class USpringArmComponent* CameraBoomComp;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
		class UCameraComponent* CameraComp;
	UPROPERTY(BlueprintReadOnly, Category = Character)
		bool bPressedJog = false;
	UPROPERTY(BlueprintReadOnly, Category = Character)
		bool bPressedAction = false;
	

	

};
