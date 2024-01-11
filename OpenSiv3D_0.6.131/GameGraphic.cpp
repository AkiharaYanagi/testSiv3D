#include "GameGraphic.h"


namespace GameLib
{

	void GameGraphic::Draw ()
	{
		tx.draw ( 0, 0 );
	}

	void GameGraphic::SetFileName ( FilePathView filepath )
	{
		tx = s3d::Texture ( filepath );
	}
}

