// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaselPawn.h"

#include "AITypes.h"
#include "Camera/CameraComponent.h"
#include "Components/DashAbility.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AWeaselPawn::AWeaselPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a Mesh for the Weasel
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,0.f);
	CameraBoom->SetRelativeRotation(FRotator(0.f,180.f,0.f));

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Create DashAbilityComponent and Attach to RootComponent
	DashAbility = CreateDefaultSubobject<UDashAbility>(TEXT("Dash"));
	
	ForceAcceleration = 500.f;

}

// Called to bind functionality to input
void AWeaselPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRightAD", this, &AWeaselPawn::MoveRight);
	PlayerInputComponent->BindAction("Dash", IE_Pressed, this, &AWeaselPawn::Dash);

}

// Called when the game starts or when spawned
void AWeaselPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWeaselPawn::MoveRight(float Value)
{
	Mesh->AddForce(FVector(0.f, -Value * ForceAcceleration * GetWorld()->GetDeltaSeconds(), 0.f));
	//UE_LOG(LogTemp, Warning, TEXT("Force: %f"), Value * ForceAcceleration * GetWorld()->GetDeltaSeconds());
}

void AWeaselPawn::Dash()
{
	Detach();
	DashAbility->Dash(this);
}

// Called every frame
void AWeaselPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

