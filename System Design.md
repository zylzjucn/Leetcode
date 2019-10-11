## Whatsapp

- 三个基本功能：

> 1. One to one chat
> 2. Sent / Delivered / Read
> 3. Push notifications

#### One to one chat

- 有多个server，horizontal scaled，server与用户间还有load balancer

- A向B发信，先发到某一个server，该server一个暂存区存储信息内容，随即向B发送。如果B在线，则接受信息，server删除信息；如果不在线则暂不删除

- Server中的暂存信息，至少要有几个属性：发送人，接收人，timestamps。同一个server中，用来存储同发送人-接收人信息的队列应该只有一个

- 所有用户上线后，要去所有有关联的server取回属于它的暂存区的信息，取回之后，server删除被取走的信息。同时所有信息有timestamps，来源为同一用户但server不同的信息需要根据timestamps merge

#### Sent / Delivered / Read

- Server收到A的信息后，会回复一个针对该信息的ACK信息给A。A收到后，该信息即可标为Sent

- 此时，server尝试向B发送信息，如果B在线，则接收信息，返回对应的Deliver给server，再返回给A

- 若B不在线，储存为sent，B上线后发回给A。如果A离线，则等A上线后取回


