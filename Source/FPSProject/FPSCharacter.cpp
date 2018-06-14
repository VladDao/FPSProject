// Fill out your copyright notice in the Description page of Project Settings.
#include "FPSCharacter.h"

#include "FPSGameMode.h"
#include "Engine.h" 




// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoomComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoomComp->TargetArmLength = 300.f;
	CameraBoomComp->AttachTo(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->AttachTo(CameraBoomComp);
	
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("We are using FPSCharacter!"));
	}
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSCharacter::OnStartJump()
{
	bPressedJump = true;
}
void AFPSCharacter::OnStopJump()
{
	bPressedJump = false;
}

void AFPSCharacter::OnStartJog()
{
	  bPressedJog = true;
}
void AFPSCharacter::OnStopJog()
{
	bPressedJog = false;
}
void AFPSCharacter::OnPressedAction()
{
	bPressedAction = true;
}
void AFPSCharacter::OnReleasedAction()
{
	bPressedAction = false;
}



// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// set up gameplay key bindings
	InputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);
	InputComponent->BindAxis("Turn", this, &AFPSCharacter::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AFPSCharacter::AddControllerPitchInput);
	InputComponent->BindAction("Jump", IE_Pressed, this, &AFPSCharacter::OnStartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacter::OnStopJump);
	InputComponent->BindAction("Jog", IE_Pressed, this, &AFPSCharacter::OnStartJog);
	InputComponent->BindAction("Jog", IE_Released, this, &AFPSCharacter::OnStopJog);
	InputComponent->BindAction("Action / Speak", IE_Pressed, this, &AFPSCharacter::OnPressedAction);
	InputComponent->BindAction("Action / Speak", IE_Released, this, &AFPSCharacter::OnReleasedAction);
	
}

void AFPSCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		// Limit pitch when walking or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}
		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		if (bPressedJog == true)
		{
			AddMovementInput(Direction, Value);
		}
		else {
			AddMovementInput(Direction, Value * 0.49);
		
		}
	}
}

void AFPSCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// add movement in that direction
		if (bPressedJog == true)
		{
			AddMovementInput(Direction, Value);
		}
		else {
			AddMovementInput(Direction, Value * 0.49);

		}
	}
}