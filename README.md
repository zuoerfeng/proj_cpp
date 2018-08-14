# proj_cpp
some small project to learn cpp 
## 2018.8.10

### 当天任务：

1、上午总结下简单的算法，主要是数据结构上的算法

>简单的基础知识回顾

（1）static能不能被重写

不能，因为static属于这个类但是属于某个对象，重写是靠虚函数完成的，对象会插入一个指向虚函数表的虚函数指针，通过这个指针来调用对应的函数，但是static是静态变量，类的对象不能直接调用它，只能通过类作用域调用，所以不能直接被重写。

（2）什么情况下不能用索引

————数据唯一性较差的字段不要使用索引

比如性别，只有两种可能的数据。意味着索引的二叉树级别少，这样的二叉树的查找无异于全局的扫描

————频繁更新的字段不要使用索引

比如登录次数，因为频繁的变化导致索引不断的更新插入删除，索引的插入删除也会降低数据库的性能

————字段不在where语句出现时不要添加索引

只有where语句出现时，mysql才回去使用索引，否则不会去使用索引

————数据量较小的表不要使用索引

数据量较小，建立索引还要花时间，这种情况全局扫描的性能可能都比较好

（3）冒泡的优化

————对每次冒泡比较的时候设置标志位，当后面的所有数据是有序的时候，这个时候不进行交换，减少遍历的次数

————相等不交换，保证排序的稳定性

（4）快排的优化

————当待排序的序列的长度分割到一定的大小之后，使用插入排序的，当待排序数量下的时候，插入排序的效率是多余快速排序的

————当数据有序的时候，设置标志位，然后退出，减少遍历的次数

————选取分割点的试试，尝试随机选取，不是总是选取最后的一个数字当做末端

（5）二叉树的最大节点个数

————二叉树的深度为n，二叉树的最大节点个数为2^n-1

————二叉树的度为2的节点数比度为1的节点数多1

（6）new和malloc的区别

————new创建内存的时候会调用对象对应的构造函数，通过new会进行安全性检查，会自动分配对象占内存的大小。

（7）malloc内存分配机制是怎么样的，在哪里分配内存，最大可以申请多大的内存

————malloc()根据用户所需分配内存的大小n (bytes)在“堆链表”（见未使用过得堆内存）里搜索。直到搜索到一个大于等于n字节的堆内存块为止。如果此堆内存块的大小刚好为n，则直接将首地址返回给用户；如果此内存块的大小大于n，则将此块堆内存分裂，将大于n部分的堆内存留在可用堆内存中，以“堆链表”的形式和其它未分配的堆内存发生联系。如果整个堆链表所代表的堆内存块都没有大于等于n的堆内存块，系统将给“堆链表”链接一个更大的区域供其使用。要是这一步也失败了，malloc()函数就返回NULL给用户。

————在堆上分配内存

————分配最大的内存取决于操作系统给进程分配的最大内存，经验是linux上最大3GB，windows上最大只有2GB

（8）讲一下new运算符的原理

————1，简单数据类型（包括基本数据类型和不需要构造函数的类型

简单类型直接调用operator new分配内存；可以通过new_handler来处理new失败的情况；new分配失败的时候不像malloc那样返回NULL，它直接抛出异常。要判断是否分配成功应该用异常捕获的机制；

————2，复杂数据类型（需要由构造函数初始化对象）

new 复杂数据类型的时候先调用operator new，然后在分配的内存上调用构造函数。

（9）new运算符重载用过吗，怎么写重载函数，重载的定义？

————首先我们要清楚，为什么我们要重载new，和delete了？这还不是指针造成的，确实指针是一件让人喜欢的东西，用起来如此让人喜欢，让人顺手。然而小程序我们完全可以避免内存泄露问题，大程序就不那么容易了，然而我们有一种特别好的方法可以跟踪我们new，和delete动作，找到未被释放的内存。办法是什么呢？微软给我们提供了一种很好的方法，那就是重载new，和delete。

（10）memset函数的作用，有哪些参数

————oid *memset(void *s,int c,size_t n)
总的作用：将已开辟内存空间 s 的首 n 个字节的值设为值 c

（11）linux系统应用程序的内存空间是怎么分配的（代码段，数据段，bss未初始化，堆，栈），一般进程空间多大，一共4GB，内核空间占1GB，用户空间占3GB。堆的最大空间是2GB

（12）模板机制了解吗，讲一下原理，类模板和函数模板在定义的时候的区别

————模板就是不考虑数据类型，是考虑逻辑，主要分为两类 ，函数模板和类模板

————首先是函数模板，它的定义方式如例子所示：
```
template <typename T>T sum(T a,T b)
{
    return a+b;
}
类也有自己的模板，称为类模板，如下所示：

template <typename T>class Proxy
{
public:
    typedef T value_type;
    Proxy();
    ~Proxy();
    value_type val;
};
 
template<typename T> Proxy<T>::Proxy()
{
    val=T(10);
}
 
template<typename T> Proxy<T>::~Proxy()
{
 
}
```
要特别注意的是，C++中类模板的声明和定义应当放到同一个.h文件下，不能将声明和定义分散在不同的文件中。

类模板定义的时候都需要加模板的头部

（13）二叉树的原理，二叉树是父节点和左右子节点。二叉树的遍历方式有前序遍历，中序遍历，后序遍历，二叉树的最大节点数2^n-1,二叉树的删除和删除的时间复杂度是lgn,节点数是n，深度就是lgn-1，查找的复杂度就是lgn，二叉树的优点查询效率高

（14）数组和链表的区别，在内存中一个是连续分配，一个是离散分配，数组的应用场景，用来存储连续的数据，例如hash表这一类，链表离散的分布，例如LRU

（15）虚继承

（16）虚函数机制，一个类有虚函数，有成员变量，求所占内存的大小（一开始没有考虑内存对其的问题，直接按照虚指针和成员变量来说，要考虑到对齐的问题）

（17）tcp和udp的区别，应用场景，一个容忍丢包，一个不容忍丢包。服务器的高并发高连接，一般是用epoll或者是libevent机制

（18）几个排序算法的练习：冒泡排序，快排，堆排

>冒泡排序
```
void Swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void BubbleSort(int A[], int n)
{
	for (int j = 0; j < n - 1; j++)         // 每次最大元素就像气泡一样"浮"到数组的最后
	{
		for (int i = 0; i < n - 1 - j; i++) // 依次比较相邻的两个元素,使较大的那个向后移
		{
			if (A[i] > A[i + 1])            // 如果条件改成A[i] >= A[i + 1],则变为不稳定的排序算法
			{
				Swap(A, i, i + 1);
			}
		}
	}
}
```

>快速排序
```
//比较函数
void Swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

//划分函数，用来划分为一个个的组
int Partition(int A[], int left, int right) 
{
	int pivot = A[right];               // 这里每次都选择最后一个元素作为基准
	int tail = left - 1;                // tail为小于基准的子数组最后一个元素的索引


	for (int i = left; i < right; i++)  // 遍历基准以外的其他元素
	{
		if (A[i] <= pivot)              // 把小于等于基准的元素放到前一个子数组末尾
		{
			Swap(A, ++tail, i);
		}
	}
	Swap(A, tail + 1, right);           // 最后把基准放到前一个子数组的后边，剩下的子数组既是大于基准的子数组
	// 该操作很有可能把后面元素的稳定性打乱，所以快速排序是不稳定的排序算法
	return tail + 1;                    // 返回基准的索引
}


//不停的进行划分组排序
void QuickSort(int A[], int left, int right)
{
	if (left >= right)
		return;
	int pivot_index = Partition(A, left, right); // 基准的索引
	QuickSort(A, left, pivot_index - 1);		//对左边分组进行在划分，知道left=right，表示划分完
	QuickSort(A, pivot_index + 1, right);		//对右边小组进行划分
}

```

>堆排序
```
//交换子函数
void Swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}


//调试堆函数，堆用一维数组存储的
void Heapify(int A[], int i, int size)  // 从A[i]向下进行堆调整
{
	int left_child = 2 * i + 1;         // 左孩子索引
	int right_child = 2 * i + 2;        // 右孩子索引
	int max = i;                        // 选出当前结点与其左右孩子三者之中的最大值

	if (left_child < size && A[left_child] > A[max])
		max = left_child;
	if (right_child < size && A[right_child] > A[max])
		max = right_child;

	if (max != i)
	{
		Swap(A, i, max);                // 把当前结点和它的最大(直接)子节点进行交换
		Heapify(A, max, size);          // 递归调用，继续从当前结点向下进行堆调整
	}
}

//把无序的数据建立一个堆 
int BuildHeap(int A[], int n)           // 建堆，时间复杂度O(n)
{
	int heap_size = n;
	for (int i = heap_size / 2 - 1; i >= 0; i--)	// 从每一个非叶结点开始向下进行堆调整
		Heapify(A, i, heap_size);
	return heap_size;
}

//进行堆排序
void HeapSort(int A[], int n)
{
	int heap_size = BuildHeap(A, n);		// 建立一个最大堆（堆顶是最大的元素）
	while (heap_size > 1)					// 堆（无序区）元素个数大于1，未完成排序
	{
		// 将堆顶元素与堆的最后一个元素互换，并从堆中去掉最后一个元素
		// 此处交换操作很有可能把后面元素的稳定性打乱，所以堆排序是不稳定的排序算法
		Swap(A, 0, --heap_size);	  //注意，这个时候交换的堆顶元素已经被取出来，堆的节点个数减少了
		Heapify(A, 0, heap_size);     // 从新的堆顶元素开始向下进行堆调整，时间复杂度O(logn)
	}
}
```

>归并排序
```
void merge(vector<int> &a,int left, int mid, int right)
{
    int len = right-left+1;
    vector<int> tmp(len);
    int index = 0;
    int i=left;
    int j=mid+1;

    while(i<=mid && j<=right)
    {
        if(a[i] <= a[j]){
            tmp[index] = a[i];
            i++;
            index++;
        }
        else{
            tmp[index] = a[j];
			index++;
			j++;
        }
    }

    while(i<=mid){
        tmp[index++] = a[i++];
    }

    while(j<=right){
        tmp[index++] = a[j++];
    }

    for(int i=0;i<len;i++)
        a[left++] = tmp[i];
}

/*
void mergesort(vector<int> &a,int left, int right)
{
    if(left == right)
        return;
    int mid = (left+right)/2;
    mergesort(a,left,mid);
    mergesort(a,mid+1,right);

    merge(a,left,mid,right);
}*/
```

2、下午继续学习k8s

>k8s的介绍

Kubernetes是Google开源的容器集群管理系统；它构建在Docker技术之上，为容器化的应用提供资源调度，部署运行，服务发现，扩容缩容等一整套功能，本质上是基于容器技术的Micro-PaaS平台，Kubernetes的灵感来源于Google内部的Borg系统

将Docker容器宿主机组成集群，统一进行资源调度，自动管理容器生命周期，提供跨节点服务发现和负载均衡；更好的支持微服务理念，划分、细分服务之间的边界，比如lablel、pod等概念的引入

轻量，迁移方便，部署快捷, 插件化，可扩展

>k8s的基本组件

k8s基本是有一个主节点master，和其他多个副节点slave来完成的，其中主节点只要是对外提供crud这些操作pod的一些命令，完成控制功能，主节点的主要组件有：Etcd,Kubernetes api server,Scheduler,Controller manager,其它的普通节点主要有Kubelet,kubeproxy等功能。

Etcd：所有的持久性状态都保存在etcd，etcd支持watch，这样组件很容易得到系统状态的变化，从而快速响应和协调工作

Kubernetes api server：主要提供Kubernetes API，提供对Pods，Services，ReplicationController等对象的CRUD处理REST操作，验证它们，在etcd中更新相应的对象API不仅仅是面向最终用户的，同时也是面向工具和扩展开发者的，是开放生态系统的基础

Scheduler：通过访问Kubernetes中/binding API, Scheduler负责Pods在各个节点上的分配
Scheduler是插件式的，Kubernetes将来可以支持用户自定义的scheduler

Controller manager：所有其它的集群级别的功能目前由Controller Manager提供
Endpoints对象由端点控制器创建和更新，节点控制器发现、管理和监控节点
Kubernetes将来可以把这些控制器拆分并提供可插拔的组件

>k8s关键基础原理

pod：在Kubernetes中，pods是能够创建、调度、和管理的最小部署单元，是一组容器的集合，而不是单独的应用容器
Pod对应于合设在一起的一组应用，它们运行在一个共享的应用上下文中
同一个Pod里的容器共享同一个网络命名空间，IP地址及端口空间和卷。
从生命周期来说，Pod是短暂的而不是长久的应用。Pods被调度到节点，保持在这个节点上直到被销毁。

ReplicaSet：ReplicaSet—副本控制器
确保Pod的一定数量的份数(replica)在运行。如果超过这个数量，控制器会杀死一些，如果少了，控制器会启动一些。
ReplicaSet用于解决pod的扩容和缩容问题。
通常用于无状态应用

StatefulSet：StatefulSet—有状态应用
用于解决各个pod实例独立生命周期管理，提供各个实例的启动顺序和唯一性
稳定，唯一的网络标识符。
稳定，持久存储。
有序的，优雅的部署和扩展。
有序，优雅的删除和终止。
有序的自动滚动更新。

DaemonSet：DaemonSet能够让所有（或者一些特定）的Node节点运行同一个pod。当节点加入到kubernetes集群中，pod会被（DaemonSet）调度到该节点上运行，当节点从kubernetes集群中被移除，被（DaemonSet）调度的pod会被移除，如果删除DaemonSet，所有跟这个DaemonSet相关的pods都会被删除。
在使用kubernetes来运行应用时，很多时候我们需要在一个区域（zone）或者所有Node上运行同一个守护进程（pod），例如如下场景：
每个Node上运行一个分布式存储的守护进程，例如glusterd，ceph
运行日志采集器在每个Node上，例如fluentd，logstash
运行监控的采集端在每个Node，例如prometheus node exporter，collectd等

## 2018.8.14

### 当天任务：

1、zk分布式的锁的实现 https://www.cnblogs.com/linjiqin/p/6052031.html

zookeeper分布式锁原理
一、分布式锁介绍
分布式锁主要用于在分布式环境中保护跨进程、跨主机、跨网络的共享资源实现互斥访问，以达到保证数据的一致性。

二、架构介绍
在介绍使用Zookeeper实现分布式锁之前，首先看当前的系统架构图

解释：左边的整个区域表示一个Zookeeper集群，locker是Zookeeper的一个持久节点，node_1、node_2、node_3是locker这个持久节点下面的临时顺序节点。client_1、client_2、client_n表示多个客户端，Service表示需要互斥访问的共享资源。

三、分布式锁获取思路
1．获取分布式锁的总体思路
a、在获取分布式锁的时候在locker节点下创建临时顺序节点，释放锁的时候删除该临时节点。

b、客户端调用createNode方法在locker下创建临时顺序节点，然后调用getChildren(“locker”)来获取locker下面的所有子节点，注意此时不用设置任何Watcher。

c、客户端获取到所有的子节点path之后，如果发现自己创建的子节点序号最小，那么就认为该客户端获取到了锁。

d、如果发现自己创建的节点并非locker所有子节点中最小的，说明自己还没有获取到锁，此时客户端需要找到比自己小的那个节点，然后对其调用exist()方法，同时对其注册事件监听器。

e、之后，让这个被关注的节点删除，则客户端的Watcher会收到相应通知，此时再次判断自己创建的节点是否是locker子节点中序号最小的，如果是则获取到了锁，如果不是则重复以上步骤继续获取到比自己小的一个节点并注册监听。


2．获取分布式锁的核心算法流程
下面同个一个流程图来分析获取分布式锁的完整算法，如下：

解释：
客户端A要获取分布式锁的时候首先到locker下创建一个临时顺序节点（node_n），然后立即获取locker下的所有（一级）子节点。

此时因为会有多个客户端同一时间争取锁，因此locker下的子节点数量就会大于1。对于顺序节点，特点是节点名称后面自动有一个数字编号，
先创建的节点数字编号小于后创建的，因此可以将子节点按照节点名称后缀的数字顺序从小到大排序，这样排在第一位的就是最先创建的顺序节点，
此时它就代表了最先争取到锁的客户端！

此时判断最小的这个节点是否为客户端A之前创建出来的node_n，如果是则表示客户端A获取到了锁，
如果不是则表示锁已经被其它客户端获取，因此客户端A要等待它释放锁，也就是等待获取到锁的那个客户端B把自己创建的那个节点删除。
此时就通过监听比node_n次小的那个顺序节点的删除事件来知道客户端B是否已经释放了锁，如果是，此时客户端A再次获取locker下的所有子节点，
再次与自己创建的node_n节点对比，直到自己创建的node_n是locker的所有子节点中顺序号最小的，此时表示客户端A获取到了锁！


3、MDC（Metadata Controller）是一个小的基于Paxos的高可靠集群，通过HA(High Availability)机制保证整个系统的高可用性和高可靠性；MDC的HA特性主要是通过多个MDC进行容灾，多个MDC之间有主备之分；多个MDC工作在“主/从”模式，即同一时刻只存在一个主MDC，其他MDC为备MDC，主MDC始终处于工作状态，备MDC则处于休眠状态；若主MDC故障，则备MDC升为主MDC提供服务，保证了整个系统的高可用性。
MDC主要完成以下功能：
（1）通过ZooKeeper集群，实现元数据（如Topology、OSD View、Partition View、VBS View等）的可靠保存；
（2）通过Partition分配算法，实现数据多份副本的RAID可靠性；
（3）通过与OSD、VBS间的消息交互，实现对OSD、VBS节点的状态变化的获取与通知；
（4）通过与Agent间的消息交互，实现系统的扩减容、状态查询、维护等；
（5）通过心跳检测机制，实现对OSD、VBS的状态监控。
