#include <irrlicht.h>

class Button
{
	public:
		Button();
		~Button();

	private:
		irr::video::ITexture	*_basic;
		irr::video::ITexture	*_hover;
//		irr::core::position2d<u32>	_pos;
//		void	(*func)(void);
};