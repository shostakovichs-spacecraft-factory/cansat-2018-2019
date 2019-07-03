#define task_begin(a) {\
		static uint32_t t_prev = 0;\
		static uint32_t t_now = 0;\
		uint32_t task_dt = 0;\
		if((t_now = HAL_GetTick()) - t_prev >= a)\
		{\
			task_dt = t_now - t_prev;
#define task_end() \
			t_prev = t_now;\
		}}
