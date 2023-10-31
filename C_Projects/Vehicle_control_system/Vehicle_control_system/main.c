#include <stdio.h>
#include <stdlib.h>

int main()
{
    int engineState = 0; /** 0: OFF, 1: ON**/
    int acState = 0;     /** 0: OFF, 1: ON**/
    int vehicleSpeed = 0;
    int roomTemperature = 0;
    int engineTemperature = 0;

    for(;;)
    {
        printf("Menu:\n");
        printf("1. Turn on the vehicle engine\n");
        printf("2. Turn off the vehicle engine\n");
        printf("3. Quit the system\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            engineState = 1; // turn on the engine
            printf("Engine is turned ON.\n");
            while(engineState)
            {
                printf("\nSensors set menu:\n");
                printf("a. Turn OFF the engine.\n");
                printf("b. Set the traffic light color.\n");
                printf("c. Set the room temperature.\n");
                printf("d. Set the engine temperature.\n");

                char sensorChoice;
                printf("Enter your choice: ");
                fflush(stdin);
                scanf("%c",&sensorChoice);
                switch(sensorChoice)
                {
                case 'a':
                    engineState = 0; //Turn off the engine
                    printf("Engine is turned OFF.\n");
                    break;
                case 'b':
                    printf("Enter the traffic light color (G / O / R): ");
                    char trafficLightColor;
                    fflush(stdin);
                    scanf("%c",&trafficLightColor);
                    if(trafficLightColor == 'G')
                    {
                        vehicleSpeed = 100;
                    }
                    else if(trafficLightColor == 'O')
                    {
                        vehicleSpeed = 30;
                    }
                    else if(trafficLightColor == 'R')
                    {
                        vehicleSpeed = 0;
                    }
                    break;
                case 'c':
                    printf("Enter the room temperature: ");
                    scanf("%d", &roomTemperature);
                    if(roomTemperature < 10)
                    {
                        acState = 1;    // AC is ON
                        roomTemperature = 20;
                    }
                    else if(roomTemperature > 30)
                    {
                        acState = 1;    // AC is ON
                        roomTemperature = 20;
                    }
                    else
                    {
                        acState = 0;    //AC is OFF
                    }
                    break;
                case 'd':
                    printf("Enter the engine temperature: ");
                    scanf("%d",&engineTemperature);
                    if(engineTemperature < 100)
                    {
                        engineTemperature = 125;
                    }
                    else if(engineTemperature > 150)
                    {
                        engineTemperature = 125;
                    }
                    else
                    {
                        engineTemperature = 0;
                    }
                    break;
                default:
                    printf("Invalid choice.\n");
            }
            printf("\nCurrent vehicle State:\n");
            printf("Engine state: %s\n", engineState ? "ON" : "OFF");
            printf("AC: %s\n", acState ? "ON" : "OFF");
            printf("Vehicle speed: %d km/hr\n",vehicleSpeed);
            printf("Room temperature: %d\n",roomTemperature);
            printf("Engine temperature controller state: %s\n", engineTemperature? "ON" : "OFF");
            printf("Engine temperature: %d\n",engineTemperature);
        }
        break;
        case 2:
            engineState = 0; //Turn OFF the engine.
            printf("Engine is turned OFF.\n");
            break;
        case 3:
            printf("Quitting the system.\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}
