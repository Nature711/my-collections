let isHappy = false;

const promise = new Promise((resolve, reject) => {
    if (isHappy) resolve('Hahaha');
    else reject('Oh no');
});

promise.then(happyWords => console.log(happyWords), err => console.log(err + 'second parameter of then')
).catch(sadWord => console.log(sadWord + 'in catch')
).finally(() => console.log('Calm down'));