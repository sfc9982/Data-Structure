数据表初态:100,12,20,31,1,5,44,66,61,200,30,80,150,4,8

第1趟后:5,12,20,4,1,30,44,66,31,8,100,80,150,61,200

第2趟后:4,1,20,5,12,30,8,61,31,44,66,80,150,100,200

第3趟后:1,4,5,8,12,20,30,31,44,61,66,80,100,150,200

---

(1)快速排序第一趟结果: 20，6，29，27，15，32，92，97，50
快速排序第二趟结果:15，6，20，27，29，32，50，92，97

(2)建成的小根堆: 6，20，15，27，97，50，92，29，32

(3)采用堆排序。因为记录的关键字基本有序时，快速排序退变成起泡排序，时间复杂度为O(n^2)，而堆在最坏情况下时间复杂度仍是 O(nlogn)。

(4)快速排序和堆排序都是不稳定排序。