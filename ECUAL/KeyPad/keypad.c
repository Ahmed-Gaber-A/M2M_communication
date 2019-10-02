/*************************************************
 * Module     : Keypad
 *
 * File name  : keypad.c
 *
 * Created on : Apr 21, 2019
 *
 * Author     : Hesham Hafez & Ahmed El-Dakhly
 *************************************************/

/*************************************************
 *              Included libraries
 *************************************************/
#include"keypad.h"

/*******************************************************************************
 *                           Static Variables                                  *
 *******************************************************************************/
static uint8_t g_row;
static uint8_t g_return;

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
uint8_t ProgramSteps=0;
uint8_t Score=0;

/*******************************************************************************
 *                           Check Configurations                              *
 *******************************************************************************/
#if(N_COL==3)
#if(N_ROW == 3)
static uint8_t KeyPad_3x3_switch(uint8_t row, uint8_t col);
#elif(N_ROW == 4)
static uint8_t KeyPad_4x3_switch(uint8_t row, uint8_t col);
#endif
#endif

#if(N_COL==4)
static uint8_t KeyPad_4x4_switch(uint8_t row, uint8_t col);
#endif

/********************************************************************************
 *              Functions Definition                                            *
 ********************************************************************************/
/********************************************************************************
 * Function Name:   KeyPad_Init
 *
 * Description:     Initialize KeyPad with Configured mode
 *
 * Inputs:          NULL
 *
 * Outputs:         NULL
 *
 * Return:          NULL
 *******************************************************************************/
void KeyPad_Init(void)
{
    /*set Pins Of KeyPad*/
    GPIO_SetPinDirection(GPIO_PORTB_DATA_BITS_R, GPIO_PIN2, INPUT, DIGITAL_ENABLE);
    GPIO_SetPinDirection(GPIO_PORTB_DATA_BITS_R, GPIO_PIN3, INPUT, DIGITAL_ENABLE);
    GPIO_SetPinDirection(GPIO_PORTB_DATA_BITS_R, GPIO_PIN6, INPUT, DIGITAL_ENABLE);
    GPIO_SetPinDirection(GPIO_PORTD_DATA_BITS_R, GPIO_PIN7, OUTPUT, DIGITAL_ENABLE);
    GPIO_SetPinDirection(GPIO_PORTD_DATA_BITS_R, GPIO_PIN6, OUTPUT, DIGITAL_ENABLE);
    GPIO_SetPinDirection(GPIO_PORTA_DATA_BITS_R, GPIO_PIN5, OUTPUT, DIGITAL_ENABLE);
    GPIO_WritePin(GPIO_PORTD_DATA_BITS_R, GPIO_PIN7, LOW);
    GPIO_WritePin(GPIO_PORTD_DATA_BITS_R, GPIO_PIN6, LOW);
    GPIO_WritePin(GPIO_PORTA_DATA_BITS_R, GPIO_PIN5, LOW);
    GPIO_UnlockPin(GPIO_PORTD_DATA_BITS_R, GPIO_PIN7, HIGH);
}

/*******************************************************************************
 * Function Name:   KeyPad_getPressedKey
 *
 * Description:     Return value of pressed key
 *
 * Inputs:          NULL
 *
 * Outputs:         NULL
 *
 * Return:          pressed key (uint8_t)
 *******************************************************************************/
uint8_t KeyPad_getPressedKey(void)
{
    /*return value*/
    //uint8_t ReturnVal=10;

    /*variables use to loop pn rows and column*/
    uint8_t row,col;

    /*Loop to check if Key is pressed to return its value*/

    for(col=0;col<N_COL;col++)
    {

        switch(col)
        {
        case 0:

            GPIO_WritePin(GPIO_PORTD_DATA_BITS_R, GPIO_PIN7, LOW);
            GPIO_WritePin(GPIO_PORTD_DATA_BITS_R, GPIO_PIN6, HIGH);
            GPIO_WritePin(GPIO_PORTA_DATA_BITS_R, GPIO_PIN5, HIGH);
            for(row=0;row<3;row++)
            {
                switch(row)
                {
                case 0:
                    if(GET_BIT((*(GPIO_PORTB_DATA_BITS_R + DATA_REGISTER_OFFSET)),GPIO_PIN2) == 0)
                    {
                        return  KeyPad_3x3_switch(row-START_ROW,col);

                    }
                    break;
                case 1:
                    if(GET_BIT((*(GPIO_PORTB_DATA_BITS_R + DATA_REGISTER_OFFSET)),GPIO_PIN3) == 0)
                    {
                        return  KeyPad_3x3_switch(row-START_ROW,col);
                    }
                    break;
                case 2:
                    if(GET_BIT((*(GPIO_PORTB_DATA_BITS_R + DATA_REGISTER_OFFSET)),GPIO_PIN6) == 0)
                    {
                        return  KeyPad_3x3_switch(row-START_ROW,col);
                    }
                    break;
                }
                break;
                case 1:
                    GPIO_WritePin(GPIO_PORTD_DATA_BITS_R, GPIO_PIN7, HIGH);
                    GPIO_WritePin(GPIO_PORTD_DATA_BITS_R, GPIO_PIN6, LOW);
                    GPIO_WritePin(GPIO_PORTA_DATA_BITS_R, GPIO_PIN5, HIGH);
                    for(row=0;row<3;row++)
                    {
                        switch(row)
                        {
                        case 0:
                            if(GET_BIT((*(GPIO_PORTB_DATA_BITS_R + DATA_REGISTER_OFFSET)),GPIO_PIN2) == 0)
                            {
                                return  KeyPad_3x3_switch(row-START_ROW,col);
                            }
                            break;
                        case 1:
                            if(GET_BIT((*(GPIO_PORTB_DATA_BITS_R + DATA_REGISTER_OFFSET)),GPIO_PIN3) == 0)
                            {
                                return  KeyPad_3x3_switch(row-START_ROW,col);
                            }
                            break;
                        case 2:
                            if(GET_BIT((*(GPIO_PORTB_DATA_BITS_R + DATA_REGISTER_OFFSET)),GPIO_PIN6) == 0)
                            {
                                return  KeyPad_3x3_switch(row-START_ROW,col);
                            }
                            break;
                        }
                    }
                        break;
                        case 2:
                            GPIO_WritePin(GPIO_PORTD_DATA_BITS_R, GPIO_PIN7, HIGH);
                            GPIO_WritePin(GPIO_PORTD_DATA_BITS_R, GPIO_PIN6, HIGH);
                            GPIO_WritePin(GPIO_PORTA_DATA_BITS_R, GPIO_PIN5, LOW);
                            for(row=0;row<3;row++)
                            {
                                switch(row)
                                {
                                case 0:
                                    if(GET_BIT((*(GPIO_PORTB_DATA_BITS_R + DATA_REGISTER_OFFSET)),GPIO_PIN2) == 0)
                                    {
                                        return  KeyPad_3x3_switch(row-START_ROW,col);
                                    }
                                    break;
                                case 1:
                                    if(GET_BIT((*(GPIO_PORTB_DATA_BITS_R + DATA_REGISTER_OFFSET)),GPIO_PIN3) == 0)
                                    {
                                        return  KeyPad_3x3_switch(row-START_ROW,col);
                                    }
                                    break;
                                case 2:
                                    if(GET_BIT((*(GPIO_PORTB_DATA_BITS_R + DATA_REGISTER_OFFSET)),GPIO_PIN6) == 0)
                                    {
                                        return  KeyPad_3x3_switch(row-START_ROW,col);
                                    }
                                    break;
                                }
                            }
                                break;
                            }
                            //        *(GPIO_PORTE_DATA_BITS_R + DIRECTION_OFFSET) = (0b00100000<<col);
                            //        *(GPIO_PORTE_DATA_BITS_R + DATA_REGISTER_OFFSET) = (~(0b00100000<<col));
                            //
                            //        for(row=START_ROW;row<END_ROW;row++)
                            //        {
                            //            if(GET_BIT((*(GPIO_PORTE_DATA_BITS_R + DATA_REGISTER_OFFSET)),row) == 0)
                            //            {
                            ////                /*global g_row flag sign the row of pressed key */
                            ////                g_row = row;
                            ////
                            ////                /*create DeBouncing Task to avoid bouncing on the pressed Key*/
                            ////                SOS_CreateTask(PRIORITY_2,4,DeBounching_Task);
                            ////
                            ////                /*check on Configurations Mode*/
#if(N_COL ==3)
#if(N_ROW == 3)

                            /*return value of pressed Key*/
                            //                return  KeyPad_3x3_switch(row-START_ROW,col);
#elif(N_ROW==4)
                            return KeyPad_4x3_switch(row-START_ROW,col);
#endif
#elif(N_COL ==4)
                            return KeyPad_4x4_switch(row-START_ROW,col);
#endif
                    }
            }
        }
        //return ReturnVal;

        /*check on Configurations Mode*/
#if(N_COL==3)

        /*check on Configurations Mode*/
#if(N_ROW == 4)

        /********************************************************************************
         * Function Name:   KeyPad_4x3_switch
         *
         * Description:     static function to return value of Pressed Key
         *
         * Inputs:          row of pressed Key (uint8_t)
         *                  column of pressed Key (uint8_t)
         *
         * Outputs:         NULL
         *
         * Return:          value of Pressed Key (uint8_t)
         *******************************************************************************/
        static uint8_t KeyPad_4x3_switch(uint8_t row,uint8_t col)
        {
            /*variable of return value*/
            uint8_t ReturnVal = 0;

            /*determine row of pressed key*/
            switch(row)
            {
            case 0:
                /*determine column of pressed key*/
                switch(col)
                {
                case 0: ReturnVal = R1C1;
                break;
                case 1: ReturnVal = R1C2;
                break;
                case 2: ReturnVal = R1C3;
                break;
                default: /*Do nothing*/
                    break;
                }
                break;

                case 1:
                    /*determine column of pressed key*/
                    switch(col)
                    {
                    case 0: ReturnVal = R2C1;
                    break;
                    case 1: ReturnVal = R2C2;
                    break;
                    case 2: ReturnVal = R2C3;
                    break;
                    default: /*Do nothing*/
                        break;
                    }
                    break;

                    case 2:
                        /*determine column of pressed key*/
                        switch(col)
                        {
                        case 0: ReturnVal = R3C1;
                        break;
                        case 1: ReturnVal = R3C2;
                        break;
                        case 2: ReturnVal = R3C3;
                        break;
                        default: /*Do nothing*/
                            break;
                        }
                        break;

                        case 3:
                            /*determine column of pressed key*/
                            switch(col)
                            {
                            case 0: ReturnVal = R4C1;
                            break;
                            case 1: ReturnVal = R4C2;
                            break;
                            case 2: ReturnVal = R4C3;
                            break;
                            default: /*Do nothing*/
                                break;
                            }
                            break;
                            default:
                                /*Do nothing*/
                                break;
            }

            /*return value of pressed key*/
            return ReturnVal;
        }

        /*check on Configurations Mode*/
#elif (N_ROW == 3)

        /********************************************************************************
         * Function Name:   KeyPad_3x3_switch
         *
         * Description:     static function to return value of Pressed Key
         *
         * Inputs:          row of pressed Key (uint8_t)
         *                  column of pressed Key (uint8_t)
         *
         * Outputs:         NULL
         *
         * Return:          value of Pressed Key (uint8_t)
         *******************************************************************************/
        static uint8_t KeyPad_3x3_switch(uint8_t row, uint8_t col)
        {

            /*variable of return value*/
            uint8_t ReturnVal = 0;

            /*determine row of pressed key*/
            switch(row)
            {
            case 0:

                /*determine column of pressed key*/
                switch(col)
                {
                case 0: ReturnVal = R1C1;
                break;
                case 1: ReturnVal = R1C2;
                break;
                case 2: ReturnVal = R1C3;
                break;
                default:/*Do nothing*/
                    break;
                }
                break;

                case 1:
                    /*determine column of pressed key*/
                    switch(col)
                    {
                    case 0: ReturnVal = R2C1;
                    break;
                    case 1: ReturnVal = R2C2;
                    break;
                    case 2: ReturnVal = R2C3;
                    break;
                    }
                    break;
                    case 2:
                        /*determine column of pressed key*/
                        switch(col)
                        {
                        case 0: ReturnVal = R3C1;
                        break;
                        case 1: ReturnVal = R3C2;
                        break;
                        case 2: ReturnVal = R3C3;
                        break;
                        }
                        break;
            }

            /*return value of pressed key*/
            return ReturnVal;
        }

#endif

        /*check on Configurations Mode*/
#elif(N_COL==4)

        /********************************************************************************
         * Function Name:   KeyPad_4x4_switch
         *
         * Description:     static function to return value of Pressed Key
         *
         * Inputs:          row of pressed Key (uint8_t)
         *                  column of pressed Key (uint8_t)
         *
         * Outputs:         NULL
         *
         * Return:          value of Pressed Key (uint8_t)
         *******************************************************************************/
        static uint8_t KeyPad_4x4_switch(uint8_t row,uint8_t col)
        {
            /*variable of return value*/
            uint8_t ReturnVal = 0;

            /*determine row of pressed key*/
            switch(row)
            {
            case 0:
                /*determine column of pressed key*/
                switch(col)
                {
                case 0: ReturnVal = R1C1;
                break;
                case 1: ReturnVal = R1C2;
                break;
                case 2: ReturnVal = R1C3;
                break;
                case 3: ReturnVal = R1C4;
                break;
                }
                break;

                case 1:
                    /*determine column of pressed key*/
                    switch(col)
                    {
                    case 0: ReturnVal = R2C1;
                    break;
                    case 1: ReturnVal = R2C2;
                    break;
                    case 2: ReturnVal = R2C3;
                    break;
                    case 3: ReturnVal = R2C4;
                    break;
                    }
                    break;

                    case 2:
                        /*determine column of pressed key*/
                        switch(col)
                        {
                        case 0: ReturnVal = R3C1;
                        break;
                        case 1: ReturnVal = R3C2;
                        break;
                        case 2: ReturnVal = R3C3;
                        break;
                        case 3: ReturnVal = R3C4;
                        break;
                        }
                        break;

                        case 3:
                            /*determine column of pressed key*/
                            switch(col)
                            {
                            case 0: ReturnVal = R4C1;
                            break;
                            case 1: ReturnVal = R4C2;
                            break;
                            case 2: ReturnVal = R4C3;
                            break;
                            case 3: ReturnVal = R4C4;
                            break;
                            }
                            break;
            }

            /*return value of pressed key*/
            return ReturnVal;
        }
#endif

        //void DeBounching_Task(void)
        //{
        //  /*LED on to calculate CPU Load because of this task*/
        //  DIO_WritePin(DIO_PIN13,HIGH);
        //
        //  /*Static variable use to switch between button cases*/
        //  static uint8_t Button_State = PREPRESSED;
        //
        //  /*Static variables to count number of entrance for this task to make de_bouncing task*/
        //  static uint8_t Press_count  = 1;
        //  static uint8_t Release_count = 10;
        //
        //  /*switch on button cases*/
        //  switch(Button_State)
        //  {
        //  case PREPRESSED:
        //      if(GET_BIT(KEYPAD_PORT_IN,g_row) == 0)
        //      {
        //          Press_count++;
        //          if(Press_count == 10)
        //          {
        //              Button_State = PRESSED;
        //          }
        //          else
        //          {
        //              /*Do Nothing*/
        //          }
        //      }
        //      break;
        //  case PRESSED:
        //      if(GET_BIT(KEYPAD_PORT_IN,g_row) == 0)
        //      {
        //          /*Do Nothing*/
        //      }
        //      else
        //      {
        //          /*check if Player Choices Yes answer or No answer only*/
        //          if((g_return==YES)||(g_return==NO))
        //          {
        //              /*check if Player Choices right answer or wrong answer*/
        //              if(g_return==Answers[ProgramSteps])
        //              {
        //                  /*increment Player's score if his answer is right*/
        //                  Score++;
        //              }
        //              /*move to next index to display next answer*/
        //              ProgramSteps++;
        //          }
        //          Button_State = PRERELEASED;
        //      }
        //      Press_count = 1;
        //      break;
        //  case PRERELEASED:
        //      if(GET_BIT(KEYPAD_PORT_IN,g_row) == 1)
        //      {
        //          Release_count--;
        //          if(Release_count == 1)
        //          {
        //              Button_State = RELEASED;
        //          }
        //          else
        //          {
        //              /*Do Nothing*/
        //          }
        //      }
        //      break;
        //  case RELEASED:
        //      Release_count = 10;
        //      Button_State = PREPRESSED;
        //
        //      /*delete this task because of its mission is done*/
        //      SOS_DeleteTask(DeBounching_Task);
        //      break;
        //  default:
        //      break;
        //  }
        //  /*LED off to calculate CPU Load because of this task*/
        //  DIO_WritePin(DIO_PIN13,LOW);
        //}
        //
        //void Key_PressedTask(void)
        //{
        //  /*LED on to calculate CPU Load because of this task*/
        //  DIO_WritePin(DIO_PIN14,HIGH);
        //
        //  /*Static variable use to synchronous between LCD Task and KeyPad Task*/
        //  static uint8_t once=0;
        //  if(once<20)
        //  {
        //      once++;
        //  }
        //  else
        //  {
        //      /*sign pressed Key with g_return to make LCD task see it*/
        //      g_return = KeyPad_getPressedKey();
        //  }
        //  /*LED off to calculate CPU Load because of this task*/
        //  DIO_WritePin(DIO_PIN14,LOW);
        //}

