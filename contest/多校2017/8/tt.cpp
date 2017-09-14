#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P = 1e9 + 7;
const int MAX_N = 1e6 + 5;
const int END = 1000000;
int check[MAX_N], prime[MAX_N], tot;
vector<int> fac[MAX_N];
ll ANS[1005] = {0, 2473330, 10735580, 25256025, 46294142, 74038525, 108598091, 150111655, 198672140, 254324912, 317187476, 387315432, 464729388, 549510707, 641756642, 741403558, 848564221, 963304947, 85569132, 215448812, 353036151, 498210042, 651163602, 811871346, 980253005, 156463647, 340526109, 532351403, 732058348, 939738564, 155189619, 378613854, 610012223, 849323865, 96618080, 352006994, 615288766, 886635740, 166122230, 453530831, 749099386, 52829179, 364550631, 684447768, 12566646, 348723414, 693060122, 45730532, 406361683, 775319108, 152636883, 537930010, 931605875, 333634249, 743712580, 162160846, 589052528, 24099004, 467427651, 919208961, 379154222, 847502459, 324308602, 809362918, 302860845, 804788157, 314978295, 833576989, 360850227, 896147587, 440050557, 992649865, 553270487, 122500717, 700354223, 286370301, 881036783, 484329876, 95974404, 716095999, 345010641, 981961405, 627621448, 282062646, 944684573, 616084587, 296161494, 984438466, 681438351, 387293134, 101201216, 824126283, 555724126, 295560973, 44135193, 801432596, 567178911, 341601879, 124875772, 916563337, 716969323, 526209552, 343733142, 170039064, 5365613, 848919991, 701392677, 562692759, 432317380, 310745568, 198208813, 93906852, 998584236, 912220319, 834107350, 764950007, 704676697, 652897981, 609906801, 575958186, 550486985, 533713464, 526224640, 526806819, 536489380, 555230645, 582218346, 618314755, 663462638, 716844891, 779218390, 850880049, 930663532, 19720021, 117783634, 224091320, 339438602, 464108612, 596865439, 738873292, 889919768, 49406184, 217950148, 395730104, 581920789, 776775713, 981217636, 193904752, 415790941, 646751924, 886118166, 134441765, 392250474, 658217787, 933497316, 218135265, 510913137, 812920114, 124114019, 443770263, 772431814, 110578127, 457094910, 812730835, 177576630, 550817709, 933308072, 325114485, 725188958, 134756750, 553546831, 980541740, 416775688, 862529500, 316374652, 779747255, 252575049, 733621142, 223826208, 723425638, 231489059, 748591370, 275464260, 810820130, 354858409, 908892854, 470765585, 42122450, 623252273, 212399257, 811170212, 419073328, 35324720, 661065308, 296325590, 939631519, 592755896, 255163955, 925780431, 606090240, 295557171, 993442500, 700701547, 417528634, 142858064, 877392055, 621533386, 373813267, 135513049, 907170593, 687047489, 476320626, 275075762, 81990575, 898189516, 724523380, 558810395, 402682643, 256225415, 117959907, 989303644, 870152019, 759391861, 657985056, 566215552, 482992300, 408920892, 344782094, 288710332, 242280077, 205287379, 176920943, 158276829, 148873394, 147975290, 156295495, 174812996, 200971236, 237214792, 283189022, 337099463, 400710654, 474189775, 555764105, 646868851, 747942084, 857244650, 975845060, 104754105, 241218472, 387772518, 543898367, 708243932, 882580006, 66609685, 258527186, 460360538, 671761917, 891598849, 120833467, 360262751, 607939589, 864835925, 131843087, 406850083, 691921596, 986450887, 289932634, 602099854, 924898184, 255197117, 595579778, 945498935, 304386457, 672732897, 50810766, 437014391, 832888322, 239064575, 652646686, 76658258, 510626180, 952418920, 403862365, 865543463, 335104891, 814685796, 304517003, 802228118, 309680704, 826941937, 352375891, 887662069, 432777877, 986305826, 549984516, 123077837, 704366196, 295489333, 896690386, 505998127, 125118200, 754918531, 391744044, 38920313, 695858578, 361278289, 36311255, 721558604, 415225356, 118095407, 831472897, 552507012, 283886416, 25075489, 774528862, 533784386, 303169864, 80416727, 867583421, 665351570, 470617247, 285860702, 111664422, 945356976, 788767153, 642597264, 504000247, 375576824, 257312861, 147511275, 47115762, 957144704, 874832796, 802693376, 740766294, 686950201, 643409919, 609417048, 583669530, 567701357, 562468075, 564860664, 577414843, 600263393, 630592921, 671455325, 722345607, 781305757, 849883309, 929046708, 16580672, 113777936, 221536319, 336523718, 461936206, 597541561, 741269161, 895323572, 59331893, 230982318, 412719798, 605099842, 805237010, 16073567, 237052865, 465156331, 704054485, 952661656, 209424671, 476626888, 753555071, 39422893, 334235831, 640351272, 954190821, 277370024, 611475647, 953821583, 306028053, 668664276, 38813754, 418888904, 810100316, 208453349, 617158661, 37520588, 464339372, 901515971, 349067138, 805107063, 270667774, 747019033, 231351227, 725615810, 230178345, 742287422, 265672052, 798214952, 339503066, 890643998, 452556830, 21637307, 601434474, 191638553, 789367470, 397852933, 16498843, 643220573, 280038132, 927276831, 581881347, 246987193, 922953069, 607124687, 300236014, 5220859, 716888514, 439155802, 172489680, 913233668, 664438364, 425824164, 194742533, 974130002, 764587833, 562062903, 370242355, 189222512, 15789186, 853145577, 699939503, 555310664, 420481732, 296335724, 180555424, 74439576, 979196356, 891019213, 813664723, 747192432, 688468889, 639657443, 602629467, 571538070, 551596817, 542017892, 540393870, 549444232, 569087526, 595471088, 633417659, 681212097, 737251971, 803109373, 880040983, 965286654, 59822506, 165368652, 278542352, 401979290, 536120062, 678410445, 831070087, 993946410, 164743870, 345687873, 537625881, 736766243, 947102933, 168170038, 396119211, 634947132, 884219419, 141558033, 408657949, 687210258, 973055729, 269289597, 576855424, 890817973, 215601626, 552049461, 895203017, 250014332, 614675461, 987043387, 369320288, 763197074, 164216191, 575603267, 998707206, 428564342, 868871444, 320254889, 779785879, 248909371, 729322099, 217431277, 715547751, 224647420, 741186945, 268117317, 806099722, 351531205, 908337830, 475290503, 50005416, 634975291, 230801302, 833727785, 448054605, 73516689, 705448511, 348294359, 2257986, 663321590, 334947808, 17967326, 708561207, 409205778, 120976191, 840301737, 570026062, 310683492, 58817225, 817972521, 587505112, 364677264, 152238064, 951491984, 757151441, 573920709, 402461451, 237496130, 83570676, 939896357, 803926913, 678795102, 564717594, 458690554, 361856034, 277326585, 199101833, 131614963, 75633979, 27229182, 989644556, 962616939, 942500977, 933561526, 936189057, 945224872, 965732847, 997262745, 35509517, 84434425, 144813216, 212061751, 290260886, 379721692, 477374256, 584849098, 703199683, 828563534, 965258438, 112549270, 267590639, 433986258, 610200911, 793890793, 988727331, 194593556, 408505935, 632132889, 867762538, 109866439, 363098064, 626836032, 898768326, 180237949, 474539736, 774785861, 86058738, 409688915, 739168088, 79822600, 430981216, 790546618, 160508608, 541765039, 929604024, 328183654, 738502464, 155557759, 584041080, 24445959, 470439089, 928243183, 396886672, 872733683, 359464509, 856892813, 362611158, 878019620, 405202723, 939848649, 484683627, 41190850, 604570245, 179451914, 765052667, 358479994, 961112750, 576951930, 198024025, 831124364, 476474824, 127719040, 789734661, 463026771, 143599855, 835010491, 537495791, 248434629, 969364023, 700927564, 440597601, 190241441, 951797982, 720617424, 500696508, 291065147, 88579182, 896830225, 717791343, 544090399, 382715005, 232902299, 89674321, 956834230, 835753156, 721359459, 617941491, 526496867, 441789056, 367747515, 306030703, 249771471, 204843537, 172785488, 146296527, 132636363, 128720015, 131671623, 145172948, 171408009, 203547898, 247821346, 303179008, 365440909, 438678106, 522932493, 614492684, 717343558, 830788633, 952705168, 83743607, 228160539, 378078430, 538837092, 712077923, 892131795, 83206065, 285606287, 494400850, 714743463, 947031062, 184937892, 434782629, 696336131, 964426555, 243661701, 534369071, 831765381, 140706577, 460058345, 788361986, 125820060, 475593005, 832424848, 199288132, 578635646, 965169675, 362932920, 771275951, 186466011, 612630480, 52004868, 495480306, 952044429, 420287589, 894291312, 380451543, 877379580, 381967888, 896229731, 423598918, 957126885, 502312809, 58364863, 620938568, 194742737, 780586753, 373440548, 978152281, 594081484, 215690137, 848592197, 493809542, 145412621, 808315771, 483118997, 163987747, 856798983, 560183879, 271504739, 993884500, 726971378, 469277339, 219350395, 983752460, 753007852, 534493793, 326212264, 126372273, 937518168, 760687371, 589995595, 429817042, 282050873, 139872158, 10977410, 893422153, 781622037, 680673057, 591938594, 509768582, 438859363, 380632205, 329026572, 287407326, 258465383, 234925853, 223959254, 224806820, 231112833, 249887181, 279901161, 316112349, 364400412, 424465869, 489912981, 567687383, 657432429, 753244782, 860999760, 979202687, 105125299, 241372307, 390996221, 547422324, 712701622, 891834989, 76107268, 271782661, 479963444, 695055157, 921118016, 158862463, 403270592, 658602475, 927445793, 200436090, 486643039, 784555753, 87381429, 402593654, 729976539, 63117399, 407787644, 764306373, 128365006, 503179361, 890246976, 282410626, 686910742, 102785811, 525535495, 960129911, 406595979, 858506461, 322045167, 797406118, 280298009, 773953160, 279781537, 792501089, 315608548, 851036114, 391623045, 945281658, 510666381, 82466071, 664445127, 260598180, 861339432, 473932751, 98250342, 729541190, 373543112, 27567550, 688185851, 360093267, 44875597, 734429817, 438086310, 152477913, 872954350, 604290461, 348764934, 98729971, 860228495, 634148487, 415820120, 206488864, 10790085, 820493141, 641231840, 475430446, 315190452, 166643693, 29965114, 900024141, 779451849, 673551218, 573321906, 484502653, 409196984, 337258717, 278613672, 230763748, 190085313, 160708177, 143032015, 133353533, 133991219, 146102553, 165460649, 196564285, 238078532, 287342003, 348488001, 421490846, 498816365, 589225953, 691751613, 799826658, 919763033, 54185076, 191997351, 342524714, 504536534, 673096894, 852672424, 44943019, 244371369, 453030930, 676081094, 903544524, 143199515, 395703658, 653915591, 924438680, 206179574, 495211851, 793861366, 106963129, 423516910, 753366630, 95813966, 444049021, 804321467, 174843367, 553488811, 941987635, 344517866, 752930211, 172567353, 604970408, 42102541, 490932806, 953551289, 421783031, 901860847, 393899623, 890459880, 400089177, 922015100, 449237575, 988854698, 541765981, 98364886, 669252004, 250409788, 838300001, 437394585, 49012802, 667907260, 296759746, 938529508, 586330778, 245393414, 916607276, 596048254, 286588548, 988582976, 694883866, 413883724, 146217700, 883982321, 633470331, 396406430, 163410990, 943272232, 734574853, 533307303, 342910282, 165424928, 993456608, 832971150, 685323265, 543307282, 411581028, 293977677, 182965446, 82486805, 996210564, 913545498, 842875977, 785756466, 732677193, 693143875, 667625937, 644440250, 634407248, 636280808, 644946542, 665418095, 697203766, 737016643, 786464926, 849560136, 917363550, 997869112, 90416583, 188990119, 300024748, 422794199, 551802168, 691929874, 845261580, 2955687, 173599674, 356856403, 546858802, 747385040, 959803164, 178619410, 409160689, 653846080, 903536314, 164117133, 437605758, 716224709, 6324869, 311178084, 619567804, 942725417, 276042502, 615137152, 967314890, 331716377, 700164702, 81984535, 477064040, 875404087, 287543739, 711065706, 142010503, 582363530, };
ll ans[MAX_N];
void init(){
    memset(check, 0, sizeof(check));
    tot = 0;
    for (int i = 2; i < MAX_N; i++){
        if (!check[i]) prime[tot++] = i;
        for (int j = 0; j < tot; j++){
            if (i * prime[j] >= MAX_N) break;
            check[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
inline ll solve(ll x, int t){
    if (!x) return 0;
    ll ret = 0;
    for (ll i = 1; i < ((ll)1 << fac[t].size()); i++){
        ll val = 1, cnt = 0;
        for (int j = 0; j < fac[t].size(); j++)
            if (i & ((ll)1 << j)) val *= fac[t][j], cnt++;
        if (cnt & 1) ret += x / val;
        else ret -= x / val;
    }
    return x - ret;
}
inline ll solve(ll res,int BEGIN,int END){
	if(ans[END]){
		printf("%lld\n",ans[END]);
		return 0;
	}
    ans[1] = 1;
    ans[BEGIN-1] = res;
    for (int i = BEGIN; i <= END; i++){
        ans[i] = ans[i - 1];
        int last = 1;
        for (int j = 1, last = 1; j <= i; j = last + 1){
            last = i / (i / j);
            ll k = i / j;
            if (i % j) k++;
            ans[i] = (ans[i] + k * (solve(last, i) - solve(j - 1, i)) % P) % P;
        }
    }
    printf("%lld\n",ans[END]);
}
int main(){
    init();
    int T,n;
    while(~scanf("%d",&n)){
    	int t = n/1000;
    	ll res = ANS[t];
		solve(res,n/1000*1000 + 1,n);
    }
    return 0;
}
