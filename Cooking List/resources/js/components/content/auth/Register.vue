<template>
    <div class="content">
        <div class="register-form">
            <form v-on:submit.prevent="send">
                <div class="section">
                    <h1>Register</h1>
                </div>
                <div class="section">
                    <div class="box">
                        <i class="fas fa-at"></i>
                        <input placeholder="E-mail" type="text" name="email" v-model="data.email"/>
                    </div>
                </div>
                <div class="section">
                    <div class="box">
                        <i class="fas fa-user"></i>
                        <input placeholder="Nick" type="text" name="name" v-model="data.name"/>
                    </div>
                </div>
                <div class="section">
                    <div class="box">
                        <i class="fas fa-key"></i>
                        <input placeholder="Password" type="password" name="password" v-model="data.password"/>
                    </div>
                </div>
                <div class="section">
                    <div class="box">
                        <i class="fas fa-key"></i>
                        <input placeholder="Repeat Password" type="password" name="repeatPassword" v-model="data.repeatPassword"/>
                    </div>
                </div>
                <div class="section">
                    <button type="submit">Login</button>
                </div>
                <div class="error">
                    {{this.backError[0]}}
                </div>
            </form>
        </div>
    </div>
</template>

<script>
export default {
    data(){
        return {
            data:{},
            backError:[]
        }
    },
    methods:{
        send(){
            this.error = {};
            axios.post('/api/auth/register',this.data).then(response=>{
                this.$router.push('/');
            }).catch(error=>{
                    this.backError.push(error.response.data.error || "");
            });
        },
    },
}
</script>

<style scoped>
    .register-form{
        padding: 100px 0px;
    }

    form{
        padding: 30px 10px;
        width: 400px;
        height: 500px;
        background: white;
        margin: 0 auto;
        box-shadow: 0px 0px 4px 0px #4d4d4d;
        border: 1px solid;
    }

    .section{
        text-align:center;
    }
    h1{
        color:#5b5b5b;
        margin-bottom: 50px;
    }

    .box {
        background: #f2f2f2;
        width: 80%;
        margin: 10px auto;
        padding: 10px 0px;
        border:1px solid;
        transition: 0.3s;
    }

    .box:hover{
        border:1px solid #2196f3;
        box-shadow: 0px 0px 3px 1px #2196F3;
    }

    .box:focus{
        border:1px solid #2196f3;
        box-shadow: 0px 0px 3px 1px #2196F3;
    }

    .section input{
        outline: 0;
        background: #f2f2f2;
        width: 80%;
        border: none;
        padding: 10px;
        box-sizing: border-box;
        font-size: 18px;
    }

    ::placeholder{
        color:#5b5b5b;
        font-size: 18px;
    }

    button{
        transition: 0.3s;
        background: #00BCD4;
        width: 80%;
        padding: 15px 0px;
        border: 0;
        font-size: 22px;
        font-weight: 600;
        color: white;
    }

    button:hover {
        background: #2196F3;
    }

    i{
        color:#5b5b5b;
        font-size: 20px;
    }

    .error {
        color: red;
        text-align: center;
        margin-top: 20px;
    }
</style>