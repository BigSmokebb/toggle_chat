//ADAPTAR SEGUN SUS NECESIDADES (NO COPIAR Y PEGAR)

#include <a_samp>
#include "zcmd"
#define MAX_TEXT_SAVE 20
#include "toggle_chat"

 //Cambiar todos los SendClientMessage a TC_SendClientMessage
public OnPlayerText(playerid, text[])
{

    new stringxd[ 256 ],namxd[24];
    GetPlayerName(playerid, namxd, 24);
    format(stringxd, 256, "%s(ID:%d): %s",namxd,playerid,text);
    for(new i = 0, j = GetPlayerPoolSize(); i <= j; i++)
    {
        if( i != INVALID_PLAYER_ID)
        {
            TC_SendClientMessage(i, 0xFF00FFFF,stringxd);
        }
    }
    return 0;
}
CMD:text(playerid)
{
    
    //
    TC_SendClientMessage(playerid, 0xFF00FF50,"Hola mundo 1");
    TC_SendClientMessage(playerid, 0xFFFF00FF,"Hola mundo 2");
    TC_SendClientMessage(playerid, 0x00FF00FF,"Hola mundo 3");
    TC_SendClientMessage(playerid, -1,"Hola mundo 4");
    TC_SendClientMessage(playerid, -1,"Hola mundo 5");
    TC_SendClientMessage(playerid, -1,"Hola mundo 6");
    TC_SendClientMessage(playerid, -1,"Hola mundo 7");
    TC_SendClientMessage(playerid, -1,"Hola mundo 8");
    return 1;
}
CMD:hide(playerid)
{
    Toggle_Chat_For_Player(playerid, false);
    return 1;
}
CMD:show(playerid)
{
    Toggle_Chat_For_Player(playerid, true);

    return 1;
}
 
