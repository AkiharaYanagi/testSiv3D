#pragma once

#include <memory>
#include <vector>



namespace GameLib
{
	class GameTask
	{
	public:
		GameTask () {}
		GameTask ( const GameTask & rhs ) = delete;
		virtual ~GameTask () {}

		virtual void Load () {}
		virtual void Rele () {}
//		virtual void Reset () {}
		virtual void Init () {}
		virtual void Move () {}

		//test
		virtual void Draw () {}
	};

	using P_Task = std::shared_ptr < GameTask >;
	using VP_Task = std::vector < P_Task >;
	using PVP_Task = std::shared_ptr < VP_Task >;



	class GameTaskVector : public GameTask
	{
		PVP_Task		mpvp_Task;
	public:
		GameTaskVector ();
		GameTaskVector ( const GameTaskVector & rhs ) = delete;
		~GameTaskVector ();

		void Load ();
		void Rele ();
//		void Reset () {}
		void Init ();
		void Move ();

		//test
		void Draw ();


		//初期化
		void Clear ();

		//配列サイズの取得
		size_t GetSize () const { return mpvp_Task->size(); }

		//配列ポインタの取得
		PVP_Task GetpvpTask () { return mpvp_Task; }

		//タスクの追加（サイズの変更も自動的に行う）
		//	※実体のある変数から&でスマートポインタを直接扱わない
		void AddpTask ( P_Task pTask );

		//タスクの取得（サイズの変更も自動的に行う）
		P_Task GetpTask ( uint32 index );

		//アクセサ		
		P_Task operator [] ( uint32 index );

		//タスクの挿入
		void InsertTask ( P_Task pTask, uint32 index );

		//タスクの取外
		void EraseTask ( P_Task pTask );
		void EraseTask ( const VP_Task::iterator it );

		//指定オブジェクトを最前列描画にする
		//	指定したオブジェクトが無い場合なにもしない
		void Top(P_Task pTask);

		//指定オブジェクトを最背列描画にする
		//	指定したオブジェクトが無い場合なにもしない
		void End(P_Task pTask);
	};

	using TASK_VEC = GameTaskVector;
	using P_TASK_VEC = std::shared_ptr < TASK_VEC >;

}
