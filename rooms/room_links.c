#include <lem_in.h>

/*
	Initialise the ->links array within a room if not previously set

	t_room *room :: Pointer to the room to init
	int max_links :: Maximum number of possible links (should be room_count)
*/
void	init_roomlink_max(t_room *room, int max_links)
{
	// TODO :: This will fail silently, depending on implementation may need to change this
	if (!room)
		return ;

	/*
		Act only if the links have not yet been init'd
	*/
	if (!room->links)
	{
		if (!(room->links = (t_room **)malloc(sizeof(t_room *) * max_links)))
			return ;
	}
}