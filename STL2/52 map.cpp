#include <iostream>
#include <string>
#include <map>           // 引入 map 容器
#include <unordered_map> // 对比说明

using namespace std;

int main() {
    // 提高输入输出效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=================== 1. map 的基本概念与初始化 ===================\n";
    /*
     * std::map 是一个【键值对 (Key-Value) 映射容器】
     * 1. 元素唯一性：Key（键）不能重复，但 Value（值）可以重复。
     * 2. 自动排序：底层是【红黑树】（平衡二叉搜索树），元素默认按照 Key 的【从小到大/字典序】自动排序。
     * 3. 复杂度：插入、查找、删除的时间复杂度均为 O(log n)。
     */

    // 定义一个键为 string (学生姓名)，值为 int (考试成绩) 的 map
    map<string, int> scores;

    // 列表初始化（C++11 风格）
    map<string, int> init_map = {
        {"Alice", 95},
        {"Bob", 88},
        {"Charlie", 92}
    };


    cout << "\n=================== 2. 插入与赋值的几种方式 ===================\n";
    // 方式 A：使用下标 []（最常用、最直观）
    scores["David"] = 80;     // 如果 "David" 不存在，则新建并赋值 80
    scores["David"] = 85;     // 如果 "David" 已存在，直接覆盖修改为 85

    // 方式 B：使用 insert() 搭配 pair 或花括号
    // 注意：如果 Key 已经存在，insert 会静默失败，不会覆盖原有数据！
    scores.insert({"Emma", 90});
    scores.insert(make_pair("Frank", 76));
    scores.insert({"Emma", 100}); // 插入失败，已经存在键为“Emma”的元素，Emma 的分数依然是 90

    // 方式 C：使用 emplace() 直接在容器内部构造（效率更高，减少拷贝）
    scores.emplace("Grace", 98);

    cout << "当前容器大小: " << scores.size() << "\n";


    cout << "\n=================== 3. 查找与判断 Key 是否存在（避坑重点！） ===================\n";
    /*
     * ⚠️ 巨坑警告（新手最容易犯的错误）：
     * 不要用 scores["Unknown"] 来判断某个 Key 是否存在！
     * 如果访问一个不存在的 Key，[] 操作符会【强制插入】该 Key，并将 Value 置为默认值 (例如 int 会变成 0)！
     * 这不仅会污染 map 的数据，还会导致 size 增大。
     */

    // 推荐做法 ①：使用 count(key)（最简洁）
    // 返回 1 表示存在，返回 0 表示不存在
    if (scores.count("David")) {
        cout << "David 存在于 map 中，成绩为：" << scores["David"] << "\n";
    }

    if (!scores.count("Nobody")) {
        cout << "Nobody 不存在于 map 中 (count 返回 0)\n";
    }

    // 推荐做法 ②：使用 find(key)（效率最高，可直接拿到对应的值）
    // 返回一个指向目标元素的迭代器；若未找到，返回 scores.end()
    auto it = scores.find("Alice");
    if (it != scores.end()) {
        // it->first 是 Key，it->second 是 Value
        cout << "找到 " << it->first << "，成绩是：" << it->second << "\n";
    } else {
        cout << "未找到 Alice\n";
    }

    // 访问元素的安全做法：at()
    // 如果 key 不存在，at() 会抛出 out_of_range 异常，而不是胡乱插入默认值
    try {
        cout << "Emma 的成绩：" << scores.at("Emma") << "\n";
        // cout << scores.at("Ghost"); // 会抛异常崩溃，保证数据安全
    } catch (const out_of_range& e) {
        cout << "捕获异常：键不存在！\n";
    }


    cout << "\n=================== 4. 遍历 map（观察自动按 Key 排序） ===================\n";
    // 插入一个无序的元素
    scores["Alex"] = 60;

    // 遍历方式 ①：C++17 结构化绑定（极其优雅，最推荐）
    cout << "--- 遍历输出 (Key 自动按字典序升序排列) ---\n";
    for (const auto& [name, score] : scores) {
        cout << "姓名: " << name << " \t成绩: " << score << "\n";
    }


    // 遍历方式 ②：C++11 pair 访问
    /*
    for (const auto& kv : scores) {
        cout << kv.first << " : " << kv.second << "\n";
    }
    */


    cout << "\n=================== 5. 删除元素 ===================\n";
    // 方式 A：根据 Key 删除（存在则删除并返回 1，不存在返回 0）
    scores.erase("Frank");

    // 方式 B：根据迭代器删除
    auto del_it = scores.find("David");
    if (del_it != scores.end()) {
        scores.erase(del_it);
    }

    cout << "删除 Frank 和 David 后的元素个数: " << scores.size() << "\n";


    cout << "\n=================== 6. 有序容器专属：二分查找 (lower/upper_bound) ===================\n";
    // 只有基于红黑树的 map/set 拥有此特性，unordered_map 没有！
    map<int, string> id_to_name = {
        {101, "Tom"},
        {105, "Jerry"},
        {110, "Spike"},
        {120, "Tyke"}
    };

    // lower_bound(k): 查找第一个 Key >= k 的元素
    auto lb = id_to_name.lower_bound(105);
    if (lb != id_to_name.end()) {
        cout << "第一个 Key >= 105 的是: " << lb->first << " -> " << lb->second << "\n"; // 105 -> Jerry
    }

    // upper_bound(k): 查找第一个 Key > k 的元素
    auto ub = id_to_name.upper_bound(105);
    if (ub != id_to_name.end()) {
        cout << "第一个 Key > 105 的是: " << ub->first << " -> " << ub->second << "\n";  // 110 -> Spike
    }


    cout << "\n=================== 7. map vs unordered_map 选型对比 ===================\n";
    /*
     * 1. std::map：
     *    - 底层：红黑树
     *    - 增删查时间复杂度：O(log n)
     *    - 优点：Key 严格有序，支持区间遍历、前驱/后继查找（lower_bound/upper_bound）
     *    - 适用：需要元素保持排序、需要按范围查询的场景
     *
     * 2. std::unordered_map：
     *    - 底层：哈希表 (Hash Table)
     *    - 增删查时间复杂度：平均 O(1)
     *    - 优点：单次查询速度极快，常数小
     *    - 适用：不需要排序，仅用于“名字查数据”、“计数统计”等纯快速查找场景（如之前的签到题目）
     */

    return 0;
}