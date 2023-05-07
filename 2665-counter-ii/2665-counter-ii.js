/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) 
{
    let curr=init;
    
    function increment()
    {
        return ++curr;
    }
    
    function decrement()
    {
        return --curr;
    }
    
    function reset()
    {
        return curr=init;
    }
    
    const ans=
          {
              increment: increment,
              decrement: decrement,
              reset: reset
          };
    
    return ans;
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */