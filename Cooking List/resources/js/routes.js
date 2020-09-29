import About from './views/About.vue';
import Home from './views/Home.vue';
import ShopList from './views/ShopList.vue';
import UserList from './views/UserList.vue';
import SingleUser from './views/SingleUser.vue';
import login from './views/auth/Login.vue';
import register from './views/auth/Register.vue';
import VueRouter from 'vue-router';
import Vue from 'vue';

Vue.use(VueRouter);

const routes = [
    { path: '/', component: Home},
    { path: '/list', component: ShopList},
    { path: '/users/', component: UserList},
    { path: '/users/:id', component: SingleUser},
    { path: '/about', component: About},
    { path: '/login', component: login},
    { path: '/register', component: register}
  ];
  
const router = new VueRouter({
    routes,
    mode:'history'
});

export default router;