// class ZombieWalking
// {
//     private PlayerBase player;

//     void ZombieWalking(PlayerBase playerInstance)
//     {
//         player = playerInstance;
//     }

//     void UpdateAnimationState(bool hasPartialZombieSuit)
//     {
//         if (hasPartialZombieSuit)
//         {
//             PlayZombieWalkAnimation();
//         }
//         else
//         {
//             PlayDefaultWalkAnimation();
//         }
//     }

//     private void PlayZombieWalkAnimation()
//     {
//         HumanCommandMove hcm = player.GetCommand_Move();
//         if (hcm)
//         {
//             hcm.SetMovementSpeedLimits(1.0, 1.0); 
//         }
//     }

//     private void PlayDefaultWalkAnimation()
//     {
//         HumanCommandMove hcm = player.GetCommand_Move();
//         if (hcm)
//         {
//             hcm.SetMovementSpeedLimits(-1, -1); // Reset speed limits to default
//         }
//     }
// }
