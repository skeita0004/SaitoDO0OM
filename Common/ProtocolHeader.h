#pragma once
#include <cstdint>

enum HEADER : uint8_t
{
	JOIN,      // CL -> SV サーバーへの参加
	RENAMED,   // SV -> CL 名前を返した
	JOINED,    // SV -> CL 参加した
	UPDATE,    // CL -> SV プレイヤーの更新処理
	UPDATED,   // SV -> CL 全体プレイヤー情報
	SHOT,      // CL -> SV 撃った
	ENDED,     // SV -> CL ゲーム終了
};
