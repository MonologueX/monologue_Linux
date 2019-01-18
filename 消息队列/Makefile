.PHONY:all
all:msg_q_s msg_q_c
msg_q_s:msg_q_s.c 
	gcc msg_q_s.c -o msg_q_s 
msg_q_c:msg_q_c.c 
	gcc msg_q_c.c -o msg_q_c 

.PHONY:clean
clean:
	rm -f msg_q_s msg_q_c
