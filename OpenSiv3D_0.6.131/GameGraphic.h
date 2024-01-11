#pragma once
# include <Siv3D.hpp> // Siv3D v0.6.13
#include "GameTask.h"
#include <memory>


namespace GameLib
{
	class GameGraphic : public GameTask
	{
		s3d::Texture tx;

	public:
		void Draw ();
		void SetFileName ( FilePathView filepath );
	};

	using P_Grp = std::shared_ptr < GameGraphic >;

}
