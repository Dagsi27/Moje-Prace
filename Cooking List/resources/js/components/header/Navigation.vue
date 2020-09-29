<template>
    <nav class="main-nav">
            <ul>
                <li><router-link to="/">Home</router-link></li>
                <li><router-link v-if="this.$store.state.user" to="/list">Shop List</router-link></li>,
                <li><router-link to="/users">Users</router-link></li>
                <li><router-link to="/about">About</router-link></li>

                <div class="user-setting" v-if="!this.$store.state.user">
                    <li><router-link to="/login">Login</router-link></li>
                    <li><router-link to="/register">Register</router-link></li>
                </div>
                <div class="user-setting" v-else>
                    <li v-on:click="logout"><a>Logout</a></li>
                </div>
            </ul>
    </nav>
</template>

<script>
export default {
    methods:{
        init(){
            axios.get('api/auth/init').then(response =>{
                this.$store.state.user = response.data.user;
                console.log(this.$store.state.user)
            })
        },
        logout(){
            axios.post('api/auth/logout').then(()=>{
                this.$store.state.user = null;
                this.$router.push('/login')
            })
        }
    },
    created(){
        this.init();
    },
    updated(){
        this.init();
    }
}
</script>

<style scoped>
    .main-nav {
        text-align: right;

    }

    ul {
        margin-right:20vh;
        font-size: 20px;
        display: inline-block;
        list-style-type: none;
    }

    a {
        color: #fff;
        text-shadow: 0px 0px 7px #000;
        text-decoration: none;
        display: block;
        transition: .5s;
    }

    li {
        float: left;
        margin-left:40px;
    }

    .user-setting{
        display: inline-block;
    }
</style>