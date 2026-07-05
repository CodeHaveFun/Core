#ifndef ERRBUILD_VN_H
#define ERRBUILD_VN_H
#include "cdbuild.h"
/*
============================
======== VIETNAMESE ========
============================
*/
inline void ERRBUILD_VN(){
    cd_input_type_error = " không phải lệnh của Core 😥";
    cd_input_type_path_error = "😫 Core éo tìm thấy file ở đường dẫn ";
    cd_input_type_path_lost_error = "BRO!😭 Đưa đường dẫn file nguồn để làm coi nào?";
    cd_input_type_path_error_file_extension = "VCL! Core chỉ nhận file đuôi '.core' thôi, đuôi khác là out trình!\n"
                                              "[MẸO]: Đổi sang '.core' đi (ví dụ: main.core, ABC.core).\n";
    cd_input_language_lost = "Ủa bro? Không nhập ngôn ngữ thì Core biết chọn gì? 😐\n"
                             "[MẸO]: Nhập lại đi, coi bảng ngôn ngữ của Core rồi điền vô nha! 😉\n";

    cd_input_error_language = "Core chưa học ngôn ngữ này bro :D\n"
                              "[MẸO]: Nhập lại đi, coi bảng ngôn ngữ trước rồi nhập vô! 😉\n";
}
/* ---- ERROR OUTPUT WHEN TYPE COMMAND CLI ---- */

#endif