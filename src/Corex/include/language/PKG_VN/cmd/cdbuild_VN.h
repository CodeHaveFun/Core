#ifndef CDBUILD_VN_H
#define CDBUILD_VN_H
#include "cdbuild.h"
/*
============================
======== VIETNAMESE ========
============================
*/
/*Command core*/

inline void CDBUILD_VN(){
cd_build = "xây";
cd_switch_language = "tiếng";
cd_version = "--bản";
cd_how_usage_cmd = R"(
Core Project | Cách sử dụng lệnh
--------------------------------
Cách dùng:
    |[VÍ DỤ LỆNH                      ]|[Giải thích                        ]|
    | core                             | Hiển thị các lệnh sử dụng của Core |
    | core --bản                       | Hiển thị phiên bản Core hiện tại   |
    | core xây <đường dẫn file nguồn>  | Biên dịch file nguồn               |
    | core tiếng <ngôn ngữ của bạn>    | Chuyển đổi ngôn ngữ                |
    
)";
}
#endif