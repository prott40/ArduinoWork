enum HC_States {HC_Nothing, HC_Heating, HC_Cooling}HC_State;// sets states for HC_States
float TempTol = 5.0; // creates varialble TempTol setting equal to value 5
int SystemInitialize() {// fucntion called n main code to active library
  HC_State = HC_Nothing;// sets current state to Nothing
  
}
  void UpdateTemperature(float CurrentTemp) {// function containing State Machine with input of current temp
    switch (HC_State) {// initiates state machine
      case HC_Nothing://  state Noting
        if (CurrentTemp >= HoldTemp + TempTol){// if CurrentTemp is greater than or equal to HoldTemp + TempTol
          HC_State = HC_Cooling; // set state to Cooling
          
        }// end if loop
        else if ( CurrentTemp <= HoldTemp - TempTol){// else if CurrentTemp is less than or equal to HoldTemp minus TempTol
          HC_State = HC_Heating;// set state to Heating
          
        }// end else if loop
        break;// break state
      case HC_Heating:// state Heating
        if (CurrentTemp >= HoldTemp){// if CurrentTemp id greater than or equal too HoldTemp
          HC_State = HC_Nothing;// set state to Nothing
          
        }// end of if loop
        break;// break state
      case HC_Cooling://  stae cooling
        if (CurrentTemp <= HoldTemp){// if currentTemp os greater than or equal too HoldTemp
          HC_State = HC_Nothing;// State is Nothing
          
        }// end of if loop
        break;// break state
    }// end of state machine
  }// end of UpdateTemperature


}// end of loop