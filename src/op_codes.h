enum OP_CODES
{
	e_null,		// 0
	e_mov_op,	// 1
	e_mvi_op,	// 2
	e_mif_op,	// 3
	e_mit_op,	// 4
	e_lri_op,	// 5
	e_ldr_op,	// 6
	e_str_op,	// 7
	e_mvr_op,	// 8
	e_add_op,	// 9
	e_addri_op,	// 10
	e_sub_op,	// 11
	e_mul_op,	// 12
	e_div_op,	// 13
	e_or_op,	// 14
	e_and_op,	// 15
	e_not_op,	// 16
	e_b_op,		// 17
	e_beq_op,	// 18
	e_bne_op,	// 19
	e_bgt_op,	// 20
	e_bge_op,	// 21
	e_blt_op,	// 22
	e_ble_op,	// 23
	e_pushd_op,	// 24
	e_pushr_op,	// 25
	e_pushi_op,	// 26
	e_popd_op,	// 27
	e_popr_op,	// 28
	e_puti_op,	// 29
	e_puts_op,	// 30
	e_line_op,	// 31
	e_geti_op,	// 32
	e_gets_op,	// 33
	e_call_op,	// 34
	e_ret_op,	// 35
	e_stop_op,	// 36

	e_num_of_ops
};	
