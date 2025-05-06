#ifndef SUBMISSION_EXERCISE82_HPP_
#define SUBMISSION_EXERCISE82_HPP_

template<typename T>
T CalcAbs(T val) {
    return (val < static_cast<T>(0)) 
         ? -val 
         :  val;
}

#endif /* SUBMISSION_EXERCISE82_HPP_ */
