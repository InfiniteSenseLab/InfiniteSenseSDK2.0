import zmq
context = zmq.Context()
socket = context.socket(zmq.SUB)
socket.connect("tcp://127.0.0.1:5555")
socket.setsockopt_string(zmq.SUBSCRIBE, "")
print("Subscribed to all messages")
while True:
    news = socket.recv_string()
    print("Received News: {}".format(news))