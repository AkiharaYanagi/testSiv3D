#include "GameTask.h"


namespace GameLib
{
	GameTaskVector::GameTaskVector()
	{
		mpvp_Task = std::make_shared < VP_Task > ();
	}

	GameTaskVector::~GameTaskVector()
	{
		Rele ();
	}

	//----------------------------------------------------------------------------------------
	//	各種インターフェースの実行
	//----------------------------------------------------------------------------------------
	void GameTaskVector::Init () { for (auto p : (*mpvp_Task)) { p->Init (); } }
	void GameTaskVector::Rele () { for (auto p : (*mpvp_Task)) { p->Rele (); } }
	void GameTaskVector::Load () { for (auto p : (*mpvp_Task)) { p->Load (); } }
//	void GameTaskVector::Reset () { for (auto p : (*mpvp_Task)) { p->Reset (); } }
	void GameTaskVector::Move () { for (auto p : (*mpvp_Task)) { p->Move (); } }
	void GameTaskVector::Draw () { for (auto p : (*mpvp_Task)) { p->Draw (); } }


	//初期化
	void GameTaskVector::Clear ()
	{
		if ( mpvp_Task ) { mpvp_Task->clear (); }
	}

	//タスクの追加（サイズの変更も自動的に行う）
	void GameTaskVector::AddpTask ( P_Task pTask )
	{
		mpvp_Task->push_back ( pTask );
	}

	//タスクの取得
	P_Task GameTaskVector::GetpTask ( uint32 index )
	{
		return mpvp_Task->at ( index );
	}

	//アクセサ
	P_Task GameTaskVector::operator [] ( uint32 index )
	{
		return mpvp_Task->at ( index );
	}

	//タスクの挿入
	void GameTaskVector::InsertTask ( P_Task pTask, uint32 index )
	{
		VP_Task::iterator it = std::begin ( * mpvp_Task );
		it += index;
		mpvp_Task->insert ( it, pTask );
	}

	//タスクの取外
	void GameTaskVector::EraseTask ( P_Task pTask )
	{
		VP_Task::iterator it = std::begin ( *mpvp_Task ) ;

		for (; it != std::end ( * mpvp_Task ); ++it )
		{
			if ( (*it) == pTask )
			{
				mpvp_Task->erase ( it );
				break;
			}
		}
	}
	void GameTaskVector::EraseTask ( const VP_Task::iterator it )
	{
		mpvp_Task->erase ( it );
	}


	//指定オブジェクトを最前列描画(末尾)にする
	//	指定したオブジェクトが無い場合なにもしない
	void GameTaskVector::Top ( P_Task pTask )
	{
		for ( auto p : (*mpvp_Task) )
		{
			if ( p == pTask )
			{
				//該当オブジェクトポインタと末尾を入れ替える
				p.swap ( * std::end ( * mpvp_Task ) );
				break;
			}
		}
	}

	//指定オブジェクトを先頭にする
	//	指定したオブジェクトが無い場合なにもしない
	void GameTaskVector::End ( P_Task pTask )
	{
		for ( auto p : (*mpvp_Task) )
		{
			if ( p == pTask )
			{
				//該当オブジェクトポインタと先頭を入れ替える
				p.swap ( * std::begin ( * mpvp_Task ) );
				break;
			}
		}
	}

}
