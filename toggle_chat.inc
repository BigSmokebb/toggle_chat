 //
// Toggle chat for player
// Show and hide the chat for the player.
// - BigSmoke_bb 2023
// - First version
//
// Version 1.0
//
//

#if !defined MAX_TEXT_SAVE
        #error "MAX_TEXT_SAVE is not defined, use MAX_TEXT_SAVE (max lines) max 20"
    #endif

#define MAX_CHAT_MESSAGE_LENGTH 267

new gSentMessages[MAX_PLAYERS][MAX_TEXT_SAVE][MAX_CHAT_MESSAGE_LENGTH];
new gSent_Color_Save[MAX_PLAYERS][MAX_TEXT_SAVE];
new bool:IsPlayerToggleChat[MAX_PLAYERS];
 

Toggle_Chat_For_Player(playerid, bool: showorno)
{
    if(showorno == true)
    {
        IsPlayerToggleChat[playerid] = false;
        for (new i = MAX_TEXT_SAVE - 1; i >= 0; i--)
        {
            if(strlen(gSentMessages[playerid][i]) > 0) SendClientMessage(playerid,gSent_Color_Save[ playerid ][ i ],gSentMessages[playerid][i]);
        }
    }
    else if(showorno == false)
    {
        IsPlayerToggleChat[playerid] = true;
        for(new i = 0; i != 32; i++) SendClientMessage(playerid, -1, " ");
    }
    return 1;
}

 

public OnPlayerConnect(playerid)
{
    for (new a = 0; a < MAX_TEXT_SAVE; a ++) 
    {
        format(gSentMessages[ playerid ][ a ], MAX_CHAT_MESSAGE_LENGTH, "");
        gSent_Color_Save[ playerid ][ a ] = -1;
    }
    return CallLocalFunction("Big_OnPlayerc", "i", playerid);
}

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect Big_OnPlayerc

forward Big_OnPlayerc(playerid);


TC_SendClientMessage(playerid, colour, message[])
{
    //new SIZE_MESSAGE[256];
    //
    // Desplazar los mensajes anteriores hacia arriba en el arreglo
    for (new i = MAX_TEXT_SAVE - 1; i > 0; i--) 
    {
        format(gSentMessages[ playerid ][ i ], MAX_CHAT_MESSAGE_LENGTH, "%s",gSentMessages[playerid][i - 1]);
        gSent_Color_Save[ playerid ][ i ] = gSent_Color_Save[ playerid ][ i - 1];

        //strcopy(gSentMessages[playerid][i], gSentMessages[playerid][i - 1], MAX_CHAT_MESSAGE_LENGTH);
    }
    gSent_Color_Save[ playerid ][ 0 ] = colour;
    format(gSentMessages[ playerid ][ 0 ], MAX_CHAT_MESSAGE_LENGTH, "%s",message);
    if(IsPlayerToggleChat[playerid] == false) SendClientMessage(playerid,colour,message);
    return 1;
}
